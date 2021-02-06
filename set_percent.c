/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_percent.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rquenten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 01:17:44 by rquenten          #+#    #+#             */
/*   Updated: 2020/12/27 01:18:06 by rquenten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_percent(va_list ap, t_flag *flag)
{
	int	*ptr;

	if (flag->type == 's')
		ft_str(ap, flag);
	else if (flag->type == 'c' || flag->type == '%')
		ft_char_percent(ap, flag);
	else if (flag->type == 'n')
	{
		ptr = va_arg(ap, int*);
		*ptr = flag->print_char;
	}
	else if (flag->type == 'p')
		ft_pointer(ap, flag);
	else if (flag->type == 'd' || flag->type == 'i')
		ft_digit_int(ap, flag);
	else if (flag->type == 'u')
		ft_unsigned(ap, flag);
	else if (flag->type == 'x' || flag->type == 'X')
		ft_hex(ap, flag);
}
