/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rquenten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 01:10:44 by rquenten          #+#    #+#             */
/*   Updated: 2020/12/27 01:11:51 by rquenten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flag_start(t_flag *flag)
{
	flag->zero = 0;
	flag->minus = 0;
	flag->plus = 0;
	flag->width = 0;
	flag->precision = -1;
	flag->type = 0;
	flag->print_char = 0;
	flag->index = 0;
	flag->error = 0;
}

void	clean_flag(t_flag *flag)
{
	flag->zero = 0;
	flag->minus = 0;
	flag->plus = 0;
	flag->width = 0;
	flag->precision = -1;
	flag->type = 0;
}

void	print_char_or_persent(va_list ap, t_flag *flag, const char *line)
{
	if (line[flag->index] == '%')
	{
		flag->index++;
		set_flag(ap, flag, line);
		set_percent(ap, flag);
		clean_flag(flag);
	}
	else
	{
		write(1, &line[flag->index], 1);
		flag->print_char++;
	}
}

int		ft_printf(const char *line, ...)
{
	t_flag	flag;
	va_list	ap;

	va_start(ap, line);
	flag_start(&flag);
	while (line[flag.index] != '\0')
	{
		print_char_or_persent(ap, &flag, line);
		if (flag.error)
		{
			va_end(ap);
			return (-1);
		}
		flag.index++;
	}
	va_end(ap);
	return (flag.print_char);
}
