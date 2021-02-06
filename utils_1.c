/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rquenten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 01:18:44 by rquenten          #+#    #+#             */
/*   Updated: 2020/12/27 01:19:31 by rquenten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	ft_str_char(const char *str, char ch)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ch)
			return (str[i]);
		i++;
	}
	return ('\0');
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
		++i;
	return (i);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr(char *str, size_t len)
{
	size_t	i;

	if (str == NULL)
		return ;
	if (ft_strlen(str) < len)
		len = ft_strlen(str);
	i = 0;
	while (i < len)
	{
		write(1, ((unsigned char*)(str + i)), 1);
		i++;
	}
}
