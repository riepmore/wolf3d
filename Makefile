# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmore <pmore@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/03 09:39:11 by pmore             #+#    #+#              #
#    Updated: 2014/01/17 23:05:20 by pmore            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d
INCLUDES = libft
SRCS = main.c map.c check.c define.c draw.c key.c
OBJECTS = $(SRCS:.c=.o)
FLAGS = -Wall -Wextra -Werror
LIB = libft

all: $(NAME)

$(NAME):
	@cd $(LIB) ; $(MAKE)
	cc -o $(NAME) $(FLAGS) $(SRCS) -I libft -L libft/ \
			-lft -L /usr/X11/lib -lmlx -lXext -lX11
	@cd $(LIB) ; $(MAKE) fclean
	@echo Creating $(NAME)...

clean:
	/bin/rm -f $(OBJECTS)
	@cd $(LIB) ; $(MAKE) fclean
	@echo Removing $(OBJECTS)...

fclean: clean
	/bin/rm -f $(NAME)
	@echo Removing $(NAME)...

re: fclean all

.PHONY: clean fclean re