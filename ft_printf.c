/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcosta <qcosta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 17:50:50 by qcosta            #+#    #+#             */
/*   Updated: 2022/06/09 18:06:19 by qcosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex_pt_len(unsigned long long int nb)
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

void	ft_pt(unsigned long long int pt)
{
	char	*base_hex;

	base_hex = "0123456789abcdef";
	if (pt <= 15)
	{
		ft_putchar(base_hex[pt]);
	}	
	if (pt >= 16)
	{
		ft_pt(pt / 16);
		ft_pt(pt % 16);
	}
}

int	ft_get_pt(unsigned long long int pt)
{
	if (!pt)
	{
		write(1, "(nil)", 5);
		return (5);
	}	
	write(1, "0x", 2);
	ft_pt(pt);
	return (2 + ft_hex_pt_len(pt));
}

int	ft_lst_format(va_list ptr_arg, char format)
{
	int	res_len;

	res_len = 0;
	if (format == '%')
		res_len += write(1, "%", 1);
	else if (format == 'd' || format == 'i')
		res_len += ft_get_nbr(va_arg(ptr_arg, int));
	else if (format == 's')
		res_len += ft_get_str(va_arg(ptr_arg, char *));
	else if (format == 'c')
		res_len += ft_putchar(va_arg(ptr_arg, int));
	else if (format == 'p')
		res_len += ft_get_pt(va_arg(ptr_arg, unsigned long long int));
	else if (format == 'u')
		res_len += ft_get_unsigned_int(va_arg(ptr_arg, unsigned int));
	else if (format == 'x')
		res_len += ft_get_hex(va_arg(ptr_arg, unsigned int));
	else if (format == 'X')
		res_len += ft_get_hex_maj(va_arg(ptr_arg, unsigned int));
	return (res_len);
}

int	ft_printf(const char *format, ...)
{
	char	*str;
	int		res;
	int		i;
	va_list	ptr_arg;

	res = 0;
	i = 0;
	va_start(ptr_arg, format);
	str = (char *)format;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			res += ft_lst_format(ptr_arg, str[i++]);
		}
		else
		{
			ft_putchar(str[i]);
			i++;
			res++;
		}
	}
	return (va_end(ptr_arg), res);
}
/*#include <stdio.h>
int	main()
{
	char	*p;
	p = NULL;
	unsigned int H = 14;
	char A;
	A = 'Z';
	unsigned int unb = -56;
	int a ;
	int nb = -75847;
	char	*str = "Bonjour";
	a  = ft_printf("hexadecimal est %x le mot%% est 
	:%s, le caractere est : %c,  le pointeur est : %pn",H,str,A, &A );
	printf("le mot est : %s  taille : %d",str, a);

	ft_printf("pointeur nul %p\n", &H);
	printf("pointeur nul %p", &H);

	
	return (0);
}*/