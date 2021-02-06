# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rquenten <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/27 01:15:18 by rquenten          #+#    #+#              #
#    Updated: 2020/12/27 01:51:31 by rquenten         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME := libftprintf.a

SRC:=	ft_printf.c \
		set_flag.c \
		set_percent.c \
		ft_str.c \
		ft_char_percent.c \
		ft_pointer.c \
		ft_hex.c \
		ft_digit_int.c \
		ft_unsigned.c \
		utils_1.c \
		utils_2.c

OBJ:= $(SRC:.c=.o)

FLAG := -c -I./ -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\033[32m"
	@ar -rus $(NAME) $(OBJ)
	@echo ''
	@echo "         \033[107;30m  /\_/\  \033[0m"
	@echo "         \033[107;30m {＾◡＾} \033[0m"
	@echo ''

%.o: %.c ft_printf.h
	gcc $(FLAG) $< -o $@

bonus: $(NAME)
	@echo "\033[32mbonus done!"

clean:
	@rm -f $(OBJ)
	@echo "\033[33mFILE.O          POOF!\033[0m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[33m$(NAME)   POOF!\033[0m"

re: fclean all
