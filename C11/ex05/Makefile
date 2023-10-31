# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yzaazaa <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/03 17:42:27 by yzaazaa           #+#    #+#              #
#    Updated: 2023/08/03 17:57:04 by yzaazaa          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = do-op

HEADER = ft.h

CC = cc

FLAGS = -Wall -Wextra -Werror

FILES  = main.c operator.c helper.c

OBJS = $(FILES:.c=.o)

all : $(NAME)

%.o : %.c $(HEADER)
	@$(CC) $(FLAGS) -c $< -o $@

$(NAME) : $(OBJS)
	@$(CC) $(FLAGS) -o $(NAME) $(OBJS)

clean :
	@rm -f $(OBJS)

fclean : clean
	@rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re
