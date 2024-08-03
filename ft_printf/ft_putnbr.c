#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int		len;
	char	num[12];
	int		i;

	i = 11;
	len = 0;
	num[i--] = '\0';
	if (n == 0)
		return (ft_putchar('0'));
	if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	if (n < 0)
	{
		len += ft_putchar('-');
		n = -n;
	}
	while (n)
	{
		num[i--] = (n % 10) + '0';
		n /= 10;
	}
	return (len + ft_putstr(&num[i + 1]));
}
