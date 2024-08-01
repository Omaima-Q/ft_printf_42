#include "ft_printf.h"

static int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

static int ft_putstr(char *str)
{
    int i;
    i = 0;
    
    if (!str)
        str = "(Null)";
    while(str[i])
        i += ft_putchar(str[i]);
    return (i);
}

// int main(void)
// {
//     ft_putstr("good");
// }

static int ft_putnbr(int n)
{
    int len;
    char num[12];
    int i;
    i = 11;

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

// int main(void)
// {
//     ft_putnbr(-1238764);
// }

static int ft_put_unsigned(unsigned int n)
{
    int len;
    char num[11];
    int i;
    i = 10;

    num[i--] = '\0';
    if (n == 0)
        return (ft_putchar('0'));
    while (n)
    {
        num[i--] = (n % 10) + '0';
        n /= 10;
    }
    return (len + (ft_putstr(&num[i + 1])));
}

// int main(void)
// {
//     ft_put_unsigned(453435);
// }

static int ft_put_hex(unsigned int n, int uppercase )
{
    char hex[9];
    char *digits;
    int i;
    i = 0;

    if (uppercase)
        digits = "0123456789ABCDEF";
    else
        digits = "0123456789abcdef";
    
    hex[i--] = '\0';
    if ( n == 0)
        return (ft_putchar('0'));
    while (n)
        {
            hex[i--] = digits[n % 16];
            n /= 16;
        }
    return (ft_putstr(&hex[i +1]));
}

// int main(void)
// {
//     ft_put_hex(12349876,0);
// }

static int ft_put_ptr(void *ptr)
{
    unsigned long long addr = (unsigned long long)ptr;
    int len;
    len = 0;

    len += ft_putstr("0x");
    return (len + ft_put_hex(addr, 0));
}

// int main (void)
// {
//     ft_put_ptr(874);
// }

int ft_printf(const char *format, ...)
{
    va_list args;
    int i;
    int printed_chars;

    va_start(args, format);
    i = 0;
    printed_chars = 0;
    while (format[i])
    {
        if (format[i] == '%' && format[i + 1])
        {
            i++;
            if (format[i] == 'c')
            printed_chars += ft_putchar(va_arg(args, int));
            else if (format[i] == 's')
            printed_chars += ft_putstr(va_arg(args, char *));
            else if (format[i] == 'p')
            printed_chars += ft_put_ptr(va_arg(args, void *));
            else if (format[i] == 'd' || format[i] == 'i')
            printed_chars += ft_putnbr(va_arg(args, int));
            else if (format[i] == 'u')
            printed_chars += ft_put_unsigned(va_arg(args, unsigned int));
            else if (format[i] == 'x')
            printed_chars += ft_put_hex(va_arg(args, unsigned int), 0);
            else if (format[i] == 'X')
            printed_chars += ft_put_hex(va_arg(args, unsigned int), 1);
            else if (format[i] == '%')
            printed_chars += ft_putchar('%');
        }
        else 
            printed_chars += ft_putchar(format[i]);
        i++;
    }
    va_end(args);
    return (printed_chars);
}

// int main(void)
// {
//     // ft_printf("omaima", );
//     ft_printf("String: %c\n", "A");
//     int x = 42;
//     ft_printf("Pointer: %p\n", &x);
// }
