# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/29 00:11:18 by leobarbo          #+#    #+#              #
#    Updated: 2024/12/27 01:17:30 by leobarbo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= cub3d
CFLAGS	:= -Wextra -Wall -Werror -Wunreachable-code -Ofast -g3
LIBFT	:= ./lib/libft
PRINTF	:= ./lib/printf
GNL		:= ./lib/gnl
LIBMLX	:= ./lib/MLX42/MLX42/MLX42/build
SRCS_PATH	:= ./src/
.SILENT:

GREEN = \033[32m
YELLOW = \033[33m
RESET = \033[0m


HEADERS	:= -I ./include -I $(LIBMLX)/include -I $(LIBFT)/include -I $(PRINTF)/include
LIBS	:= ${LIBFT}/libft.a $(PRINTF)/libftprintf.a $(GNL)/gnl.a $(LIBMLX)/libmlx42.a -lXext -lX11 -lm

SRCS	:= $(shell find $(SRCS_PATH) -type f -name "*.c")

OBJS	:= ${SRCS:%.c=%.o}


all: libft printf $(NAME)

libmlx:
	$(MAKE) -C ${LIBMLX} all

gnl:
	$(MAKE) -C ${GNL} all

libft:
	$(MAKE) -C ${LIBFT} all

printf:
	$(MAKE) -C ${PRINTF} all

%.o: %.c
	$(CC) $(HEADERS) $(CFLAGS) -o $@ -c $<

$(NAME): $(OBJS)
	printf "$(YELLOW)Compiling...$(RESET)\n"
	$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)
	printf "$(GREEN)Done!\n$(RESET)"

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re, libmlx, libft, printf
