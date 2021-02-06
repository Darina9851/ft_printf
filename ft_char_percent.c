/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_percent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rquenten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 01:21:10 by rquenten          #+#    #+#             */
/*   Updated: 2020/12/27 01:21:49 by rquenten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	set_and_fill(t_flag *flag, char ch)
{
	ft_putchar_fd(ch, 1);
	while (--flag->width > 0)
		write(1, " ", 1);
}

static void	fill_and_set(t_flag *flag, char ch, char fill_char)
{
	while (--flag->width > 0)
		write(1, &fill_char, 1);
	ft_putchar_fd(ch, 1);
}

static void	print_str(t_flag *flag, char ch)
{
	if (flag->width > 1)
	{
		if (flag->minus)
			set_and_fill(flag, ch);
		else if (flag->zero)
			fill_and_set(flag, ch, '0');
		else
			fill_and_set(flag, ch, ' ');
	}
	else
		ft_putchar_fd(ch, 1);
}

void		ft_char_percent(va_list args, t_flag *flag)
{
	char	ch;

	if (flag->type == 'c')
		ch = (char)va_arg(args, int);
	else
		ch = '%';
	if (flag->width > 1)
		flag->print_char += flag->width;
	else
		flag->print_char += 1;
	print_str(flag, ch);
}
