/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rquenten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 01:25:12 by rquenten          #+#    #+#             */
/*   Updated: 2020/12/27 01:25:29 by rquenten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	set_and_fill(t_flag *flag, char *str, int len)
{
	ft_putstr(str, len);
	while (--flag->width > len - 1)
		write(1, " ", 1);
}

static void	fill_and_set(t_flag *flag, char *str, int len, char fill_char)
{
	while (--flag->width > len - 1)
		write(1, &fill_char, 1);
	ft_putstr(str, len);
}

static void	print_str(t_flag *flag, char *str, long len)
{
	if (flag->width > len)
	{
		if (flag->minus)
			set_and_fill(flag, str, len);
		else if (flag->zero)
			fill_and_set(flag, str, len, '0');
		else
			fill_and_set(flag, str, len, ' ');
	}
	else
		ft_putstr(str, len);
}

void		ft_str(va_list ap, t_flag *flag)
{
	char	*str;
	int		len;

	str = va_arg(ap, char*);
	if (str == NULL)
		str = "(null)";
	len = ft_strlen(str);
	len = flag->precision > -1 && flag->precision < len ? flag->precision : len;
	flag->print_char += flag->width > len ? flag->width : len;
	print_str(flag, str, len);
}
