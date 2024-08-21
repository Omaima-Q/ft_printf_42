/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_unsigned.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oqaroot <oqaroot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 20:40:06 by oqaroot           #+#    #+#             */
/*   Updated: 2024/08/03 21:53:15 by oqaroot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_unsigned(unsigned int n)
{
	int		len;
	char	num[11];
	int		i;

	i = 10;
	len = 0;
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
