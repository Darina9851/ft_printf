/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rquenten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 01:19:44 by rquenten          #+#    #+#             */
/*   Updated: 2020/12/27 01:19:57 by rquenten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		count_len_hex(unsigned long long hex)
{
	int	len;

	if (hex < 16)
		return (1);
	else
	{
		hex /= 16;
		len = count_len_hex(hex) + 1;
		return (len);
	}
}

void	ft_puthex(long long hex, char type)
{
	char	ch;

	if (hex < 16)
	{
		if (type == 'x' || type == 'p')
			ch = hex > 9 ? hex + 87 : hex + '0';
		else
			ch = hex > 9 ? hex + 55 : hex + '0';
		write(1, &ch, 1);
	}
	else
	{
		ch = hex % 16;
		if (type == 'x' || type == 'p')
			ch = ch > 9 ? ch + 87 : ch + '0';
		else
			ch = ch > 9 ? ch + 55 : ch + '0';
		hex /= 16;
		ft_puthex(hex, type);
		write(1, &ch, 1);
	}
}

void	ft_putnum(long num)
{
	char	ch;

	num = num < 0 ? -num : num;
	if (num < 10)
	{
		ch = num + 48;
		write(1, &ch, 1);
	}
	else
	{
		ch = num % 10 + 48;
		ft_putnum(num / 10);
		write(1, &ch, 1);
	}
}

int		count_len_digit(long num)
{
	num = num < 0 ? num * -1 : num;
	if (num < 10)
		return (1);
	else
	{
		num /= 10;
		return (count_len_digit(num) + 1);
	}
}
