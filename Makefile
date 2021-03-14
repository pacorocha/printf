# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/10 15:45:06 by jfrancis          #+#    #+#              #
#    Updated: 2021/03/14 14:08:43 by jfrancis         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS = -g -Wall -Wextra -Werror
LIBFT = libft.a
FILES = ft_printf.c ft_putchar.c ft_putstr.c
OBJS = $(FILES:.c=.o)
RM = rm -f
INCLUDE = ./libft

%.o: %.c
			$(CC) -c -o $@ $< $(CFLAGS)

$(NAME):	$(OBJS) $(INCLUDE)
			$(CC) $(FLAGS) -c $(FILES)
			make -C $(INCLUDE)
			cp libft/libft.a .
			mv libft.a $(NAME)
			ar -rcs $(NAME) $(OBJS)
			ranlib $(NAME)

			$(CC) -g -L . libftprintf.a main.c

all:		$(NAME)

clean:
			$(RM) $(OBJS)
			make -C $(INCLUDE) clean

fclean:		clean
			$(RM) $(NAME)
			make -C $(INCLUDE) fclean

re:			fclean all

.PHONY::	all clean fclean re