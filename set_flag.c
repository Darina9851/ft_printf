/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_flag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rquenten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 01:16:07 by rquenten          #+#    #+#             */
/*   Updated: 2020/12/27 01:17:22 by rquenten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_plus_minus_zero(t_flag *flag, const char *line)
{
	char symbol;

	symbol = line[flag->index];
	while (symbol == '+' || symbol == '-' || symbol == '0')
	{
		if (symbol == '+')
			flag->plus = 1;
		if (symbol == '-')
			flag->minus = 1;
		if (symbol == '0')
			flag->zero = 1;
		if (flag->minus)
			flag->zero = 0;
		flag->index++;
		symbol = line[flag->index];
	}
}

void	set_width(va_list ap, t_flag *flag, const char *line)
{
	char symbol;

	symbol = line[flag->index];
	if (symbol == '*')
	{
		flag->width = va_arg(ap, int);
		if (flag->width < 0)
		{
			flag->width *= -1;
			flag->minus = 1;
			flag->zero = 0;
		}
		flag->index++;
	}
	else
	{
		while ('0' <= symbol && symbol <= '9')
		{
			flag->width = flag->width * 10 + (symbol - '0');
			flag->index++;
			symbol = line[flag->index];
		}
	}
}

void	set_precision(va_list ap, t_flag *flag, const char *line)
{
	char symbol;

	if (line[flag->index] != '.')
		return ;
	flag->precision = 0;
	flag->index++;
	symbol = line[flag->index];
	if (symbol == '*')
	{
		flag->precision = va_arg(ap, int);
		flag->index++;
	}
	else
	{
		while ('0' <= symbol && symbol <= '9')
		{
			flag->precision = flag->precision * 10 + (symbol - '0');
			flag->index++;
			symbol = line[flag->index];
		}
	}
	if (flag->precision > -1)
		flag->zero = 0;
}

void	set_flag(va_list ap, t_flag *flag, const char *line)
{
	while (line[flag->index] != '\0')
	{
		set_plus_minus_zero(flag, line);
		set_width(ap, flag, line);
		set_precision(ap, flag, line);
		flag->type = ft_str_char("ncspdiuxX%", line[flag->index]);
		if (flag->type)
			break ;
		if (ft_str_char("+-.0123456789ncspdiuxX%", line[flag->index]) == '\0')
			flag->index++;
	}
	if (flag->type == '\0')
		flag->error = 1;
}
