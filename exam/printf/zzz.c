#include <stdarg.h>
#include <unistd.h>

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
	char	*s, *str, *base;
	long	num;
	int		leng = 0, width = 0, prec = 0, bolprec = 0, base_len, zeros = 0, space = 0, n = 0, neg = 0;
	va_list	valist;
	
	str = (char *)format;
	va_start(valist, format);
	while (*str)
	{
		if (*str == '%')
		{	
			str++;
			width = 0, prec = 0, bolprec = 0, zeros = 0, space = 0, n = 0, neg = 0;
			while (*str >= '0' && *str <= '9')
			{
				width = width * 10 + *str - '0';				// 처음에 while문으로 width, prec 값들 받는 것 주의 !!
				str++;
			}
			if (*str == '.')
			{
				str++;
				while (*str >= '0' && *str <= '9')
				{
					prec = prec * 10 + *str - '0';
					str++;
				}
				bolprec = 1;
			}
			if (*str == 's')
			{										// 구분자에서는 str++을 하지 않음 // 왜나면 나중에 출력할 때 구분자를 사용해야 하기 때문 
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
				base_len = 10;
				base = "0123456789";
				n = ft_numlen(num, base_len);
				if (n < 0)
				{
					n = n * -1;
					neg = 1;
				}
			}
			if (bolprec && prec >= n && *str != 's')
				zeros = prec - n + neg;
			if (bolprec && prec < n && *str == 's')
				n = prec;
			if (bolprec && prec == 0 && (*str == 's' || num == 0))
				n = 0;
			space = width - n - zeros;
			while (space-- > 0)
			{
				write(1, " ", 1);
				leng++;
			}
			if (neg)
				write(1, "-", 1);
			while (zeros-- > 0)
			{
				write(1, "0", 1);
				leng++;
			}
			if (*str == 's')
				write(1, s, n);
			else if (n > 0)
				ft_putnum(num, base_len, base);
			leng += n;
			str++;
		}
		else
		{
			write(1, str, 1);
			leng++;
			str++;
		}
	}
	return (leng);
}
