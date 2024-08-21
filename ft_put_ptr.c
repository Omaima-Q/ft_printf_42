/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oqaroot <oqaroot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 20:41:57 by oqaroot           #+#    #+#             */
/*   Updated: 2024/08/03 19:43:40 by oqaroot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

int	ft_put_ptr(void *ptr)
{
	int				len;
	unsigned long	n;

	len = 0;
	n = (unsigned long)ptr;
	write(1, "0x", 2);
	len += 2;
	if (ptr == NULL)
	{
		write(1, "0", 1);
		len += 1;
	}
	else
	{
		ft_put_hex(n, 0);
	}
	return (len);
}
