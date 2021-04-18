#include <unistd.h>
#include <stdarg.h>

int		ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}


int		ft_numlen(int n, int base_num)		// long long n, int base_len
{
	int i;
	
	i = 1;
	while (n >= base_len || n <= -base_len)	/// 작거나 같은 곳에는 -부호 붙여야 함
	{
		n = n / base_num;
		i++;
	}
	return (i);
}

int		ft_putnum(int n, char *base, int num)	//	(long long n, int base_len, char *base)  이 함수 다시 보기
{
	if (n >= base_len)
		ft_putnum(n / base_len, base_len, base);
	write(1, &base[n % base_len], 1);
}

int		ft_printf(char *format, ...)
{
	va_list		valist;
	char		*s, *str, *base;	// *base
	long		num;				// long num;
	int			prec = 0, width = 0, bolprec = 0, zeros = 0, neg = 0, base_len, n = 0, leng = 0, space = 0; //xxxx(num = 0)xxx, // leng = 0 // space = 0;

	str = (char *)format;
	va_start(valist, str);
	
	// 처음에는 while문으로 시작해야 함
	while (*str != '\0')
	{
		if (*str == '%')
		{
			str++;	// 이걸 해야 % 다음으로 가니까
			// % 들어오고 초기화도 한 번 해줘야 함
			prec = 0, width = 0, bolprec = 0, zeros = 0, space = 0, n = 0, neg = 0; // neg = 0;
			while (*str >= '0' && *str <= '9')
			{
				width = width * 10 + (*str - 48);
				str++;
			}
			if (*str == '.')
			{
				str++; // 이걸 해야 . 다음으로 가니까
				while (*str >= 0 && *str <= 9)
				{
					prec = prec * 10 + (*str - 48);
					str++;
				}
				bolprec = 1;
			}
			// if문에 구분자가 들어올 때마다 va_arg를 사용해줘야 함
			if (*str == 's')	// s가 제일 쉬움
			{
				s = va_arg(valist, char *);
				if (!s)
					s = "(null)";
				n = ft_strlen(s);
			}
			if (*str == 'x')
			{
				num = va_arg(valist, unsigned);
				base = "0123456789abcdef";
				base_len = 16;
				n = ft_numlen(num, base_len);
			}
			if (*str == 'd')
			{
				num = va_arg(valist, int);
				base = "0123456789";
				base_len = 10;
				if (num < 0)
				{
					num = num * -1;
					neg = 1;
				}
				n = ft_numlen(num, base_len) + neg;
			}
			if (bolprec == 1 && prec > n && *str != 's')
				zeros = prec - n + neg;
			else if(bolprec == 1 && prec <= n && *str == 's')
				n = prec;										// prec = n 아님// n(자리수)을 바꿔줘야 함
			else if(bolprec == 1 && prec == 0 && (*str == 's' || num == 0))
				n = 0;
			space = width - n - zeros;		// width임 
			while (space-- > 0)
			{
				write(1, " ", 1);
				leng++;
			}
			if (neg == 1)
				write(1, "-", 1);		// space랑 zeros 사이에 neg가 있어야 함
			while (zeros-- > 0)
			{
				write(1, "0", 1);
				leng++;
			}
			if (*str == 's')
				write(1, s, n);
			else if (n >0)
				ft_putnum(num, base_len, base);
			leng += n;
			str++;
		}
