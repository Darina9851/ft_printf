/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rquenten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 01:25:57 by rquenten          #+#    #+#             */
/*   Updated: 2020/12/27 01:26:14 by rquenten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	fill_and_set(t_flag *flag, long num, int len, char ch)
{
	while (flag->width > flag->precision && flag->width > len)
	{
		write(1, &ch, 1);
		flag->width--;
	}
	while (--flag->precision > len - 1)
		write(1, "0", 1);
	if (len > 0)
		ft_putnum(num);
}

static void	set_and_fill(t_flag *flag, long num, int len)
{
	int	tmp;

	tmp = flag->precision;
	while (--flag->precision > len - 1)
		write(1, "0", 1);
	if (len > 0)
		ft_putnum(num);
	while (flag->width > len && flag->width > tmp)
	{
		write(1, " ", 1);
		flag->width--;
	}
}

void		print_unsigned(t_flag *flag, long num, int len)
{
	if (flag->width > len && flag->width > flag->precision)
	{
		if (flag->minus)
			set_and_fill(flag, num, len);
		else if (flag->zero)
			fill_and_set(flag, num, len, '0');
		else
			fill_and_set(flag, num, len, ' ');
	}
	else
	{
		while (--flag->precision > len - 1)
			write(1, "0", 1);
		if (len > 0)
			ft_putnum(num);
	}
}

void		ft_unsigned(va_list ap, t_flag *flag)
{
	long	num;
	int		len;

	num = va_arg(ap, unsigned int);
	len = count_len_digit(num);
	if (flag->precision == 0 && num == 0)
		len = 0;
	if (flag->width > len && flag->width > flag->precision)
		flag->print_char += flag->width;
	else if (len > flag->precision)
		flag->print_char += len;
	else
		flag->print_char += flag->precision;
	print_unsigned(flag, num, len);
}
