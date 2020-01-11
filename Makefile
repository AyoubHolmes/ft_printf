# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aboulbaz <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/10 16:53:06 by aboulbaz          #+#    #+#              #
#    Updated: 2020/01/10 16:53:09 by aboulbaz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
FUNCTIONS = ft_isdigit.c ft_putchar_fd.c ft_strlen.c hexa_majuscule_handler.c is_a_conversion.c type_of_arg.c \
			char_handler.c ft_putstr_fd.c ft_uitia.c hexa_minuscule_handler.c pointer_handler.c \
			unsigned_int_handler.c controller.c help_printer.c int_handler.c percentage_handler.c print.c string_handler.c \
			ft_atoi.c ft_printf.c initializer.c struct_initializer.c
FUNCTIONS_O = ft_isdigit.o ft_putchar_fd.o ft_strlen.o hexa_majuscule_handler.o is_a_conversion.o type_of_arg.o \
			char_handler.o ft_putstr_fd.o ft_uitia.o hexa_minuscule_handler.o pointer_handler.o \
			unsigned_int_handler.o controller.o help_printer.o int_handler.o percentage_handler.o print.o string_handler.o \
			ft_atoi.o ft_printf.o initializer.o struct_initializer.o
CC = gcc -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(FUNCTIONS_O) libftprintf.h
	ar rc $(NAME) ${FUNCTIONS_O}
clean:
	rm -rf $(FUNCTIONS_O)

fclean: clean
	rm -rf $(NAME)

re: fclean all
