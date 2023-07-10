# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gcoqueir <gcoqueir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/12 11:19:15 by gcoqueir          #+#    #+#              #
#    Updated: 2023/07/10 08:54:54 by gcoqueir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror -g -I$(INC)
XFLAGS =  -lmlx -lXext -lX11
INC = ./include
LIBFT = ./libft
RM = rm -f
FILES = srcs/so_long.c \
		srcs/valid.c \
		srcs/valid_utils.c \
		srcs/valid_map_draw.c \
		srcs/valid_map_draw2.c \
		srcs/exit.c \
		srcs/map_memory.c \
		srcs/game_init.c \
		srcs/take_sprites.c \
		srcs/fill_map.c \
		srcs/put_images.c \
		srcs/gameplay.c \
		srcs/steps.c \
		srcs/ending_animation.c \
		srcs/free_images.c
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