# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gcoqueir <gcoqueir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/12 11:19:15 by gcoqueir          #+#    #+#              #
#    Updated: 2023/06/14 12:06:50 by gcoqueir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror -g -I$(INC)
INC = ./include
LIBFT = ./libft
RM = rm -f
FILES = so_long.c valid.c valid_utils.c valid_map_draw_utils.c \
			error.c memory_usage.c
OBJS = $(FILES:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@make -C $(LIBFT)
	$(CC) $(OBJS) $(CFLAGS) $(LIBFT)/libft.a -o $(NAME)

clean:
	@make clean -C $(LIBFT)
	@$(RM) $(OBJS)

fclean: clean
	@make fclean -C $(LIBFT)
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re