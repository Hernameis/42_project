#include <unistd.h>
#include <stdarg.h>

int			ft_strlen(char *s)
{
	int		i;

	i = 0;
	while(s[i])
		i++;
	return (i);
}

int			ft_numlen(long long num, int base_len)		// long long n으로 해야 함
{
	int		i;

	i = 1;
	while (num >= base_len || num <= -base_len)
	{
		n = n / base_len;
		i++;
	}
	return (i);
}

void		ft_putnum(long long num, int base_len, char *base)		// long long n으로 해야 함
{
	if (num >= base_len)								// -(음수)일 경우는 필요없음
		ft_putnum(num / base_len, base_len, base);
	write(1, &base[num % base_len], 1);					// write의 첫번쨰 인자로는 1, 2번째 인자에는 &가 꼭 들어가야 함
}


int			ft_printf(char *format, ...)
{
	va_list		valist;
	char		*s, *str, *base;
	long long	num;
	int			width = 0, prec = 0, bolprec = 0, n = 0, base_len, zeros = 0, space = 0, leng = 0, neg = 0;

	str = (char *)format;
	va_start(valist, format);		// str로 받았으니 va_start(valist, str); 이 맞음

	while (*str)
	{
		if (*str == '%')
		{
			str++;
			// 초기화 해줘야 함!!!!!!!!!!!!!!!!!!!!!!!!!!
			prec = 0, width = 0, bolprec = 0, n = 0, zeros = 0, space = 0, neg = 0;		// 초기화 꼭 해줄 것
			while (*str >= '0' && *str <= '9')
			{
				width = width * 10 + (*str - '0');
				str++;
			}
			if (*str == '.')
			{
				str++;
				while (*str >= '0' && *str <= '9')			 // 이 while문이 '.' if문 안에 있어야 함
				{												// 여기는 prec임
					prec = prec * 10 + (*str - '0');		
					str++;
				}
				bolprec = 1;
			}
			if (*str == 's')
			{
				s = va_arg(valilst, char *);
				if (!s)								// s가 없을 경우 예외처리 해줘야 함
					s = "(null)";			
				n = ft_strlen(s);					// str++ 할 필요 없음
			}
			if (*str == 'x')
			{
				num = va_arg(valist, unsigned);
				base_len = 16;
				base = "0123456789abcdef";
				n = ft_numlen(num);
				str++;								// 이거 필요 없음
			}
			if (*str == 'd')
			{
				num = va_arg(valist, int);
				base_len = 10;
				base = "0123456789";
				if (num < 0)
				{
					num = num * -1;
					neg = 1;						// 얘가 if문 안에 들어와야지 성호야...
				}
				n = ft_numlen(num);		// n = ft_numlen(num, base_len) 으로 함수를 써야하고, d의 경우에는 + neg;를 해줘야 함
				str++					// 이거 필요 없음
			}
			if (bolprec == 1 && prec >= n && *str != 's')
				zeros = n - prec;									// zeros = prec - n + neg; 임 (zeros에 neg가 포함되어 있음)
			else if (bolprec == 1 && prec < n && *str == 's')
				n = prec;
			else if (bolprec == 1 && prec == 0 && (*str == 's' || num == 0))
				n = 0;
			space = width - n - zeros			// 이미 zeros에 neg가 계산되어 있음
			while (space--)
			{
				write(1, " ", 1);
				leng++;							//leng++ 해줘야 함 (write를 하는 것이기 때문)
			}
			if (neg)
				write(1, "-", 1);
			while (zeros--)
			{
				write(1, "0", 1);
				leng++;							// leng++ 해줘야 함
			}
			if (*str == 's')
				write(1, s, n);
			else	// else if (n > 0)					//  이게 아니라 else if로 해서 (n > 0) 일 경우에 출력하는 것을 조건으로 해야 함
				ft_putnum(num, base_len, base);
			leng += n;
			str++;				// 여기는 반복문의 끝이므로 당연히 str++ 을 해줘야 함
		}

/////////
		else
		{
			write(1, str, 1);
			leng++;
			str++;
		}
	}
	return (leng);
}
