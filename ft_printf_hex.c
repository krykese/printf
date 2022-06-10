/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcosta <qcosta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 12:22:07 by qcosta            #+#    #+#             */
/*   Updated: 2022/06/09 17:58:43 by qcosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex_len(unsigned int nb)
{
	int	len;

	len = 0;
	while (nb != 0)
	{
		len++;
		nb = nb / 16;
	}
	return (len);
}

void	ft_conv_hex(unsigned int x)
{
	char	*base_hex;

	base_hex = "0123456789abcdef";
	if (x <= 15)
	{
		ft_putchar(base_hex[x]);
	}	
	if (x >= 16)
	{
		ft_conv_hex(x / 16);
		ft_conv_hex(x % 16);
	}
}	

void	ft_conv_hex_maj(unsigned int x)
{
	char	*base_hex;

	base_hex = "0123456789ABCDEF";
	if (x <= 15)
	{
		ft_putchar(base_hex[x]);
	}
	if (x >= 16)
	{
		ft_conv_hex_maj(x / 16);
		ft_conv_hex_maj(x % 16);
	}
}

int	ft_get_hex(unsigned int x)
{
	ft_conv_hex(x);
	if (x == 0)
		return (1);
	return (ft_hex_len(x));
}

int	ft_get_hex_maj(unsigned int x)
{
	ft_conv_hex_maj(x);
	if (x == 0)
		return (1);
	return (ft_hex_len(x));
}
