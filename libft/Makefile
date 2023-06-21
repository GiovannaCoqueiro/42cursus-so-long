# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gcoqueir <gcoqueir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/12 09:09:09 by gcoqueir          #+#    #+#              #
#    Updated: 2023/06/21 16:19:01 by gcoqueir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -I../include
RM = rm -f
FILES = ft_strlen.c ft_strjoin.c ft_strchr.c ft_strncmp.c get_next_line.c \
			ft_printf.c print_char.c print_str.c print_ptr.c print_nbr.c \
			print_unint.c print_hex.c ft_itoa.c
OBJS = $(FILES:.c=.o)
GREEN = \033[1;32m
NORMAL = \033[0m

all: $(NAME)
	@echo "$(GREEN)libft is ready!$(NORMAL)"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re