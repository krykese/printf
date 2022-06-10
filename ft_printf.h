/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcosta <qcosta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 15:31:11 by qcosta            #+#    #+#             */
/*   Updated: 2022/06/09 17:57:15 by qcosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stddef.h>

int		ft_putchar(char c);
void	ft_putstr(char *s);
int		ft_strlen(const char *s);
int		ft_get_str(char *s);
int		ft_unsigned_len(unsigned int nb);
void	ft_unsigned_int(unsigned int nb);
int		ft_get_unsigned_int(unsigned int nb);
int		ft_nbr_len(int n);
void	ft_putnbr(int n);
int		ft_get_nbr(int n);
int		ft_hex_len(unsigned int nb);
void	ft_conv_hex(unsigned int x);
void	ft_conv_hex_maj(unsigned int x);
int		ft_get_hex(unsigned int x);
int		ft_get_hex_maj(unsigned int x);
int		ft_hex_pt_len(unsigned long long int nb);
void	ft_pt(unsigned long long int pt);
int		ft_get_pt(unsigned long long int pt);
int		ft_lst_format(va_list ptr_arg, char format);
int		ft_printf(const char *format, ...);

#endif