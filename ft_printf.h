/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oqaroot <oqaroot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 19:49:51 by oqaroot           #+#    #+#             */
/*   Updated: 2024/08/04 13:52:54 by oqaroot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_put_hex(unsigned long long n, int uppercase);
int	ft_put_ptr(void *ptr);
int	ft_put_unsigned(unsigned int n);
int	ft_putchar(char c);
int	ft_putnbr(int n);
int	ft_putstr(const char *str);
int	ft_printf(const char *format, ...);

#endif
