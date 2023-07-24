# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gcoqueir <gcoqueir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/12 11:19:15 by gcoqueir          #+#    #+#              #
#    Updated: 2023/07/24 11:50:35 by gcoqueir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3 -I$(INC)
XFLAGS =  -lmlx -lXext -lX11
INC = ./include
LIBFT = ./libft
RM = rm -f
FILES = srcs/so_long.c srcs/valid.c srcs/valid_map_draw.c \
		srcs/valid_map_draw2.c srcs/exit.c srcs/map_memory.c \
		srcs/game_init.c srcs/take_sprites.c srcs/fill_map.c \
		srcs/put_images.c srcs/gameplay.c srcs/steps.c \
		srcs/ending_animation.c srcs/free_images.c
BONUS_FILES = srcs/so_long.c srcs/valid.c srcs/valid_map_draw.c \
		srcs/valid_map_draw2_bonus.c srcs/exit.c srcs/map_memory.c \
		srcs/game_init.c srcs/take_sprites.c srcs/fill_map.c \
		srcs/put_images.c srcs/gameplay.c srcs/steps.c \
		srcs/ending_animation.c srcs/free_images.c
OBJS = $(FILES:.c=.o)
BONUS_OBJS = $(BONUS_FILES:.c=.o)

all: $(NAME)
	@echo "SUCCESS!!"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@make -C $(LIBFT)
	@$(CC) $(OBJS) $(CFLAGS) $(LIBFT)/libft.a -o $(NAME) $(XFLAGS)

bonus: $(BONUS_OBJS)
	@make -C $(LIBFT)
	@$(CC) $(BONUS_OBJS) $(CFLAGS) $(LIBFT)/libft.a -o $(NAME) $(XFLAGS)

clean:
	@make clean -C $(LIBFT)
	@$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	@make fclean -C $(LIBFT)
	@$(RM) $(NAME)

re: fclean all

rebonus: fclean bonus

.PHONY: all clean fclean re bonus rebonus