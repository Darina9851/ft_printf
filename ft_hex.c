/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rquenten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 01:23:50 by rquenten          #+#    #+#             */
/*   Updated: 2020/12/27 01:24:03 by rquenten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	fill_and_set(t_flag *flag, long long *hex, int len, char ch)
{
	while (flag->width > len && flag->width > flag->precision)
	{
		write(1, &ch, 1);
		flag->width--;
	}
	while (--flag->precision > len - 1)
		write(1, "0", 1);
	if (len > 0)
		ft_puthex(*hex, flag->type);
}

static void	set_and_fill(t_flag *flag, long long *hex, int len)
{
	int	tmp;

	tmp = flag->precision;
	while (--flag->precision > len - 1)
		write(1, "0", 1);
	if (len > 0)
		ft_puthex(*hex, flag->type);
	while (flag->width > len && flag->width > tmp)
	{
		write(1, " ", 1);
		flag->width--;
	}
}

static void	width(t_flag *flag, long long *hex, int len)
{
	if (flag->minus)
		set_and_fill(flag, hex, len);
	else if (flag->zero)
		fill_and_set(flag, hex, len, '0');
	else
		fill_and_set(flag, hex, len, ' ');
}

static void	length(t_flag *flag, long long *hex, int len)
{
	while (--flag->precision > len - 1)
		write(1, "0", 1);
	if (len > 0)
		ft_puthex(*hex, flag->type);
}

void		ft_hex(va_list ap, t_flag *flag)
{
	int			len;
	long long	hex;

	hex = va_arg(ap, unsigned int);
	len = count_len_hex(hex);
	if (hex == 0 && flag->precision == 0)
		len = 0;
	if (flag->width > len && flag->width > flag->precision)
		flag->print_char += flag->width;
	else if (len > flag->precision)
		flag->print_char += len;
	else
		flag->print_char += flag->precision;
	if (flag->width > len)
		width(flag, &hex, len);
	else
		length(flag, &hex, len);
}
