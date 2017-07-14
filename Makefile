#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vpoltave <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/14 21:33:33 by vpoltave          #+#    #+#              #
#    Updated: 2017/02/17 11:16:04 by vpoltave         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fillit
CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I .
M_OBJECTS =	./main.o					\
			./fck_fill_coordinate.o		\
			./fck_recursia_mazarfaka.o	\
			./fck_figure.o				\
			./fck_validation.o			\

all : $(NAME)
$(NAME) : $(M_OBJECTS)
	$(CC) $(CFLAGS) -o $(NAME) $(M_OBJECTS)
%.o : ./%.c
	$(CC) $(CFLAGS) -o $@ -c $< $(INCLUDES)
clean :
	rm -rf $(M_OBJECTS)
fclean : clean
	rm -rf $(NAME)
re : fclean all