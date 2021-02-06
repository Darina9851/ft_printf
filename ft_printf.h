/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rquenten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 01:12:11 by rquenten          #+#    #+#             */
/*   Updated: 2020/12/27 01:14:07 by rquenten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

typedef struct	s_flag
{
	int			zero;
	int			minus;
	int			width;
	int			precision;
	char		type;
	int			print_char;
	int			index;
	int			plus;
	int			error;
}				t_flag;

/*
** ______________ft_printf______________
*/

void			flag_start(t_flag *flag);
void			clean_flag(t_flag *flag);
int				ft_printf(const char *line, ...);

/*
** ______________set_flag______________
*/

void			set_plus_minus_zero(t_flag *flag, const char *line);
void			set_width(va_list ap, t_flag *flag, const char *line);
void			set_precision(va_list ap, t_flag *flag, const char *line);
void			set_flag(va_list ap, t_flag *flag, const char *line);

/*
** ______________set_percent______________
*/

void			set_percent(va_list ap, t_flag *flag);

/*
** ______________ft_str______________
*/

void			ft_str(va_list ap, t_flag *flag);

/*
** ______________ft_char_percent______________
*/

void			ft_char_percent(va_list args, t_flag *flag);

/*
** ______________ft_pointer______________
*/

void			ft_pointer(va_list ap, t_flag *flag);

/*
** ______________ft_hex______________
*/

void			ft_hex(va_list ap, t_flag *flag);

/*
** ______________ft_digit_int______________
*/

void			ft_digit_int(va_list ap, t_flag *flag);
void			print_digit_int(t_flag *flag, long num, int min_pluss, int len);

/*
** ______________ft_unsigned______________
*/

void			ft_unsigned(va_list ap, t_flag *flag);
void			print_unsigned(t_flag *flag, long num, int len);

/*
** ______________utils______________
*/

char			ft_str_char(const char *str, char ch);
size_t			ft_strlen(const char *str);
void			ft_putstr(char *str, size_t len);
void			ft_putchar_fd(char c, int fd);
int				count_len_hex(unsigned long long hex);
int				count_len_digit(long num);
void			ft_puthex(long long hex, char type);
void			ft_putnum(long num);

#endif
