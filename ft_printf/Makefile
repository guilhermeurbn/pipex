# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: guisanto <guisanto@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/15 13:15:51 by guilhermeur       #+#    #+#              #
#    Updated: 2024/11/21 14:27:36 by guisanto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc
INCLUDES_DIR = includes
SRCS	= ft_print_char.c \
			ft_print_digit_n_negative.c \
			ft_print_digit_pointer.c \
			ft_print_digit_upper.c \
			ft_print_pointer.c \
			ft_print_digit.c \
			ft_print_str.c \
			ft_printf.c \

CFLAGS = -Wall -Werror -Wextra -I $(INCLUDES_DIR)

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)

%.o: %.c
	@$(CC) $(CFLAGS) -c -o $@ $^

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all
