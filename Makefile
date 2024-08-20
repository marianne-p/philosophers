# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpihur <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/20 14:38:53 by mpihur            #+#    #+#              #
#    Updated: 2024/08/20 14:48:16 by mpihur           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := philo
SRC := main.c libft.c
OBJ := $(SRC:.c=.o)

$(NAME): $(OBJ)
	cc $< $@ 

%.o = %.c
	cc -Wall -Wextra -Werror -c $< -o $@

all:
	$(NAME)

clean:	rm -rf $(OBJ)

fclean: clean
		rm $(NAME)

re: fclean all

.PHONY: clean fclean re all 
