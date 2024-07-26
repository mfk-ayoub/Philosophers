# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/12 15:19:41 by ayel-mou          #+#    #+#              #
#    Updated: 2024/07/23 14:45:03 by ayel-mou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
INCLUDE = philo.h
CFLAGS = -Wall -Wextra -Werror -pthread -g
CC = cc 
# debug = -fsanitize=thread -g

SRC:= $(wildcard *.c)


OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%.o : %.c $(INCLUDE)
	$(CC) $(CFLAGS)  -c $<

clean:
	rm -f $(OBJ)

fclean: clean
	@if [ -f $(NAME) ]; then rm -f $(NAME); fi

re: fclean all

