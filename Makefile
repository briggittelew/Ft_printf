# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: karlewis <karlewis@student.42urduliz.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/16 16:07:44 by karlewis          #+#    #+#              #
#    Updated: 2023/07/07 17:28:58 by karlewis         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAG = -Wall -Wextra -Werror
UTILS = ft_printf.c ft_print.c
INCLUDE= ft_printf.h
OBJS = $(UTILS:.c=.o)
all: $(NAME)
$(NAME): $(OBJS) $(INCLUDE)
		ar rcs $(NAME) $(OBJS)
clean:
		$(RM) $(OBJS)
fclean:clean
		$(RM) $(NAME)
re: fclean $(NAME)
.PHONY: all clean fclean re bonus