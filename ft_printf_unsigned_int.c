/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsigned_int.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcosta <qcosta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 12:10:45 by qcosta            #+#    #+#             */
/*   Updated: 2022/06/09 14:29:16 by qcosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unsigned_len(unsigned int nb)
{
	unsigned int	len;

	len = 0;
	if (nb == 0)
		return (1);
	while (nb != 0)
	{
		len++;
		nb = nb / 10;
	}
	return (len);
}

void	ft_unsigned_int(unsigned int nb)
{
	if (nb <= 9)
	{
		ft_putchar(nb + '0');
	}
	else
	{
		ft_unsigned_int(nb / 10);
		ft_unsigned_int(nb % 10);
	}
}

int	ft_get_unsigned_int(unsigned int nb)
{
	ft_unsigned_int(nb);
	return (ft_unsigned_len(nb));
}
