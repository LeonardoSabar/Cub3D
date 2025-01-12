# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/29 00:11:18 by leobarbo          #+#    #+#              #
#    Updated: 2025/01/12 19:46:04 by leobarbo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        := cub3d
CC          := gcc
CFLAGS      := -Wextra -Wall -Werror -Wunreachable-code -Ofast -g3 -fPIC
LIBFT       := ./lib/libft
LIBMLX42_PATH := ./lib/MLX42
LIBMLX_REPO := https://github.com/codam-coding-college/MLX42.git
SRCS_PATH   := ./src/
.SILENT:

GREEN = \033[32m
YELLOW = \033[33m
RESET = \033[0m

HEADERS     := -I ./include -I $(LIBMLX42_PATH)/include -I $(LIBFT)/include
LIBS        := ${LIBFT}/libft.a $(LIBMLX42_PATH)/build/libmlx42.a -lglfw -ldl -lXext -lX11 -lm
SRCS        := $(shell find $(SRCS_PATH) -type f -name "*.c")
OBJS        := $(SRCS:%.c=%.o)

all: libmlx42 libft $(NAME)

libft:
	@$(MAKE) -C $(LIBFT)

$(LIBMLX42_PATH):
	@git clone $(LIBMLX_REPO) $(LIBMLX42_PATH)

libmlx42: $(LIBMLX42_PATH)
	cmake -S $(LIBMLX42_PATH) -B $(LIBMLX42_PATH)/build
	make -C $(LIBMLX42_PATH)/build -j4

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

.PHONY: all clean fclean re libmlx42 libft
