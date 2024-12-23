# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/29 00:11:18 by leobarbo          #+#    #+#              #
#    Updated: 2024/12/23 15:55:24 by leobarbo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= cub3d
CFLAGS	:= -Wextra -Wall -Werror -Wunreachable-code -Ofast -g3
LIBFT	:= ./lib/libft
PRINTF	:= ./lib/printf
SRCS_PATH	:= ./src/
NAME_BONUS	:= cub3d_bonus
SRCS_PATH_BONUS	:= ./bonus/
.SILENT:

GREEN = \033[32m
YELLOW = \033[33m
RESET = \033[0m

ifdef WITH_BONUS
	NAME	:= $(NAME_BONUS)
	SRCS	:= $(SRCS_BONUS)
	OBJS	:= $(OBJS_BONUS)
endif

HEADERS	:= -I ./include -I $(LIBMLX)/include -I $(LIBFT)/include -I $(PRINTF)/include
LIBS	:= ${LIBFT}/libft.a $(PRINTF)/libftprintf.a -ldl -lglfw -pthread -lm

# Use o comando find para buscar recursivamente os arquivos .c
SRCS	:= $(shell find $(SRCS_PATH) -type f -name "*.c")
SRCS_BONUS	:= $(shell find $(SRCS_PATH_BONUS) -type f -name "*.c")

# Converte os arquivos .c para .o
OBJS	:= ${SRCS:%.c=%.o}
OBJS_BONUS	:= ${SRCS_BONUS:%.c=%.o}

all: libft printf $(NAME)

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
	rm -rf $(OBJS_BONUS)

fclean: clean
	rm -rf $(NAME)
	rm -rf $(NAME_BONUS)

re: fclean all

bonus:
	$(MAKE) WITH_BONUS=TRUE

.PHONY: all, clean, fclean, re, libmlx, libft, printf, bonus
