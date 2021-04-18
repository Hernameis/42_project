#include <unistd.h>
#include <stdarg.h>

int		ft_strlen(char *s)
{
	int		i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int		ft_numlen(long long n, int base_len)
{
	int		i;

	i = 1;
	while (n >= base_len || n <= -base_len)
	{
		n = n / base_len;
		i++;
	}
	return (i);
}

void	ft_putnum(long long n, int base_len, char *base)
{
	if (n >= base_len)
		ft_putnum(n / base_len, base_len, base);
	write(1, &base[n % base_len], 1);
}

int		ft_printf(char *format, ...)
{
	char		*s, *str, *base;
	long long	num;
	int			width = 0, prec = 0, bolprec = 0, n = 0, base_len, zeros = 0, space = 0, neg = 0, leng = 0;
	va_list		valist;

	va_start(valist, str);			// vastart로 format을 먼저 받고 시작하면 됨
	str = (char *)format;

	while (*str)
	{
		if (*str == '%')
		{
			str++;
			width = 0, prec = 0, bolprec = 0, n = 0, zeros = 0, space = 0, neg = 0;
			while (*str >= '0' && *str <= '9')
			{
				width = width * 10 + *str - '0';
				leng++;									// leng ++이 아니라 str++임/.....while 문 안에서 계속 돌아야해서
			}
			if (*str == '.')
			{
				str++;
				while (*str >= '0' && *str <= '9')
				{
					prec = prec * 10 + *str - '0';
					leng++;								//leng++이 아니라 str++임...
				}
				bolprec = 1;
			}
			if (*str == 's')
			{
				s = va_arg(valist, char *);
				if (!s)
					s = "(null)";
				n = ft_strlen(s);
			}
			if (*str == 'x')
			{
				num = va_arg(valist, unsigned);
				base_len = 16;
				base = "0123456789abcdef";
				n = ft_numlen(num, base_len);
			}
			if (*str == 'd')
			{
				num = va_arg(valist, int);
				if (num < 0)
				{
					neg = 1;
					num = num * -1;
				}
				base_len = 10;
				base = "0123456789";
				n = ft_numlen(num, base_len) + neg;
			}
			if (bolprec == 1 && prec >= n && *str != 's')
				zeros = prec - n + neg;
			else if (bolprec == 1 && prec < n && *str == 's')
				n = prec;
			else if (bolprec == 1 && prec == 0 && (*str == 's' || num == 0))
				n = 0;
			space = width - zeros - n;
			while (space--)
			{
				write(1, " ", 1);
				leng++;
			}
			if (neg)
				write(1, "-", 1);
			while (zeros--)
			{
				write(1, "0", 1);
				leng++;
			}
			if (*str == 's')
				write(1, str, n);
			else if (n >= 0)						// 등호는 없어야 함
				ft_putnum(num, base_len, base);
			leng = leng + n;
			str++;
		}
		else
		{
			write(1, str, 1);
			str++;
			leng++;
		}
	}
	return (leng);
}
