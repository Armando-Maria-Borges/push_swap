# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aborges <aborges@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/29 16:23:53 by aborges           #+#    #+#              #
#    Updated: 2024/08/05 20:45:41 by aborges          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT = ./includes/libft/libft.a
FTPRINTF = ./includes/ft_printf/libftprintf.a
INCS = ./includes
SRCS = ./srcs/push_swap.c ./srcs/push_swap_utils.c ./srcs/push_swap_utils_two.c ./srcs/push_operations.c \
	   ./srcs/push_operations_two.c ./srcs/push_operations_three.c ./srcs/sort_value.c ./srcs/sort_value_two.c\
	   ./srcs/check_arg.c ./srcs/check_arg_two.c ./srcs/sort_value_min.c

OBJS = $(SRCS:.c=.o)
RM = rm -drf

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(FTPRINTF)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(FTPRINTF) -o $(NAME) 

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(FTPRINTF):
	make -C $(INCS)/ft_printf

$(LIBFT):
	make -C $(INCS)/libft

clean:
	$(RM) $(OBJS)
	make clean -C $(INCS)/libft
	make clean -C $(INCS)/ft_printf

fclean: clean
	$(RM) $(NAME)
	make fclean -C $(INCS)/libft
	make fclean -C $(INCS)/ft_printf

re: fclean all
	make re -C $(INCS)/libft
	make re -C $(INCS)/ft_printf

