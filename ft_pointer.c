/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rquenten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 01:24:32 by rquenten          #+#    #+#             */
/*   Updated: 2020/12/27 01:24:44 by rquenten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	fill_and_set(t_flag *flag, unsigned long long hex,
							int len, char ch)
{
	while (flag->width > len && flag->width > flag->precision)
	{
		write(1, &ch, 1);
		flag->width--;
	}
	write(1, "0x", 2);
	while (--flag->precision > len - 3)
		write(1, "0", 1);
	if (len > 2)
		ft_puthex(hex, flag->type);
}

static void	set_and_fill(t_flag *flag, unsigned long long hex, int len)
{
	int	tmp;

	tmp = flag->precision;
	write(1, "0x", 2);
	while (--flag->precision > len - 3)
		write(1, "0", 1);
	if (len > 2)
		ft_puthex(hex, flag->type);
	while (flag->width > len && flag->width > tmp)
	{
		write(1, " ", 1);
		flag->width--;
	}
}

static void	width(t_flag *flag, unsigned long long hex, int len)
{
	if (flag->minus)
		set_and_fill(flag, hex, len);
	else if (flag->zero)
		fill_and_set(flag, hex, len, '0');
	else
		fill_and_set(flag, hex, len, ' ');
}

static void	length(t_flag *flag, unsigned long long hex, int len)
{
	write(1, "0x", 2);
	while (--flag->precision > len - 3)
	{
		write(1, "0", 1);
		flag->print_char++;
	}
	if (len > 2)
		ft_puthex(hex, flag->type);
}

void		ft_pointer(va_list ap, t_flag *flag)
{
	int					len;
	unsigned long long	hex;

	hex = (unsigned long long)va_arg(ap, void*);
	len = count_len_hex(hex) + 2;
	if (hex == 0 && flag->precision == 0)
		len = 2;
	flag->print_char += flag->width > len ? flag->width : len;
	if (flag->precision > -1 && flag->zero)
		flag->zero = 0;
	if (flag->width > len)
		width(flag, hex, len);
	else
		length(flag, hex, len);
}
