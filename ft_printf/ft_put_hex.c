#include "ft_printf.h"

int	ft_print_hex_recursive(unsigned long long n, const char *digits)
{
	int	count;

	count = 0;
	if (n >= 16)
	{
		count = ft_print_hex_recursive(n / 16, digits);
	}
	ft_putchar(digits[n % 16]);
	return (count + 1);
}

int	ft_put_hex(unsigned long long n, int uppercase)
{
	char	*digits;

	if (uppercase)
		digits = "0123456789ABCDEF";
	else
		digits = "0123456789abcdef";
	if (n == 0)
		return (ft_putchar('0'));
	return (ft_print_hex_recursive(n, digits));
}
