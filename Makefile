# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/29 00:11:18 by leobarbo          #+#    #+#              #
#    Updated: 2025/01/11 15:21:19 by leobarbo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= cub3d
CFLAGS	:= -Wextra -Wall -Werror -Wunreachable-code -Ofast -g3
LIBFT	:= ./lib/libft
PRINTF	:= ./lib/printf
LIBMLX42_PATH := ./lib/MLX42
SRCS_PATH	:= ./src/
.SILENT:

GREEN = \033[32m
YELLOW = \033[33m
RESET = \033[0m

HEADERS	:= -I ./include -I $(LIBMLX42_PATH)/include -I $(LIBFT)/include -I $(PRINTF)/include
LIBS	:= ${LIBFT}/libft.a $(PRINTF)/libftprintf.a $(LIBMLX42_PATH)/build/libmlx42.a -lglfw -ldl -lXext -lX11 -lm
SRCS	:= $(shell find $(SRCS_PATH) -type f -name "*.c")
OBJS	:= ${SRCS:%.c=%.o}

all: libmlx42 libft printf $(NAME)

libmlx42:
	# Navega para dentro de MLX42 e chama o CMake para construir a libmlx42.a
	cmake -S $(LIBMLX42_PATH) -B $(LIBMLX42_PATH)/build
	make -C $(LIBMLX42_PATH)/build

libft:
	$(MAKE) -C ${LIBFT} all

printf:
	$(MAKE) -C ${PRINTF} all

%.o: %.c
	$(CC) $(HEADERS) $(CFLAGS) -o $@ -c $<

$(NAME): $(OBJS)
	printf "$(YELLOW)Compiling...$(RESET)\n"
	$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)
	printf "$(GREEN)Done!$(RESET)\n"

clean:
	rm -rf $(OBJS)
	rm -rf $(LIBMLX42_PATH)/build

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re, libmlx42, libft, printf
