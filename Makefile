# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gcoqueir <gcoqueir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/12 11:19:15 by gcoqueir          #+#    #+#              #
#    Updated: 2023/06/26 16:55:50 by gcoqueir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror -g -I$(INC)
XFLAGS =  -lmlx -lXext -lX11
INC = ./include
LIBFT = ./libft
RM = rm -f
FILES = so_long.c \
		valid.c \
		valid_utils.c \
		valid_map_draw.c \
		valid_map_draw2.c \
		exit.c \
		map_memory.c \
		game_init.c \
		take_sprites.c \
		fill_map.c \
		put_images.c \
		gameplay.c \
		steps.c \
		ending_animation.c \
		free_images.c
OBJS = $(FILES:.c=.o)
GREEN = \033[1;32m

all: $(NAME)
	@echo "$(GREEN)SUCCESS!!"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@make -C $(LIBFT)
	@$(CC) $(OBJS) $(CFLAGS) $(LIBFT)/libft.a -o $(NAME) $(XFLAGS)

bonus: all

clean:
	@make clean -C $(LIBFT)
	@$(RM) $(OBJS)

fclean: clean
	@make fclean -C $(LIBFT)
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re