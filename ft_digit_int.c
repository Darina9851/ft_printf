/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digit_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rquenten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 01:22:17 by rquenten          #+#    #+#             */
/*   Updated: 2020/12/27 01:23:09 by rquenten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	fill_and_set(t_flag *flag, long num, int len, char ch)
{
	int	minus_plus;

	minus_plus = num < 0 || flag->plus ? 1 : 0;
	if (flag->plus && num > 0 && flag->zero)
		write(1, "+", 1);
	if (num < 0 && flag->zero)
		write(1, "-", 1);
	while (flag->width > len && flag->width > flag->precision + minus_plus)
	{
		write(1, &ch, 1);
		flag->width--;
	}
	if (flag->plus && num > 0 && !flag->zero)
		write(1, "+", 1);
	if (num < 0 && !flag->zero)
		write(1, "-", 1);
	while (--flag->precision > len - minus_plus - 1)
		write(1, "0", 1);
	if (len > 0)
		ft_putnum(num);
}

static void	set_and_fill(t_flag *flag, long num, int len)
{
	int	tmp;
	int	minus_plus;

	minus_plus = num < 0 || flag->plus ? 1 : 0;
	tmp = flag->precision + minus_plus;
	if (flag->plus && num > 0)
		write(1, "+", 1);
	if (num < 0)
		write(1, "-", 1);
	while (--flag->precision > len - minus_plus - 1)
		write(1, "0", 1);
	if (len > 0)
		ft_putnum(num);
	while (flag->width > len && flag->width > tmp)
	{
		write(1, " ", 1);
		flag->width--;
	}
}

void		print_digit_int(t_flag *flag, long num, int minus_plus, int len)
{
	if (flag->width > len && flag->width > flag->precision + minus_plus)
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
		if (flag->plus && num > 0)
			write(1, "+", 1);
		if (num < 0)
			write(1, "-", 1);
		while (--flag->precision > len - minus_plus - 1)
			write(1, "0", 1);
		if (len > 0)
			ft_putnum(num);
	}
}

void		ft_digit_int(va_list ap, t_flag *flag)
{
	long	num;
	int		len;
	int		minus_plus;

	num = va_arg(ap, int);
	len = count_len_digit(num);
	minus_plus = num < 0 || flag->plus ? 1 : 0;
	len += minus_plus;
	if (flag->precision == 0 && num == 0)
		len = 0;
	if (flag->width > len && flag->width > flag->precision + minus_plus)
		flag->print_char += flag->width;
	else if (len > flag->precision + minus_plus)
		flag->print_char += len;
	else
		flag->print_char += flag->precision + minus_plus;
	print_digit_int(flag, num, minus_plus, len);
}
