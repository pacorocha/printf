# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/10 15:45:06 by jfrancis          #+#    #+#              #
#    Updated: 2021/03/20 20:00:22 by jfrancis         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIBFT = libft.a

CC = gcc
CFLAGS = -g -Wall -Wextra -Werror
FILES = ft_printf.c ft_putchar.c ft_putstr.c check_params.c
OBJS = $(FILES:.c=.o)
RM = rm -f
LIBFT_PATH = ./libft

%.o: %.c
			$(CC) -c -I ./includes -o $@ $< $(CFLAGS)

$(NAME):	$(OBJS) $(LIBFT_PATH)
			$(CC) -I ./includes $(FLAGS) -c $(FILES)
			make -C $(LIBFT_PATH) $(LIBFT)
			cp $(LIBFT_PATH)/$(LIBFT) .
			mv $(LIBFT) $(NAME)
			ar -rcs $(NAME) $(OBJS)

all:		$(NAME)

clean:
			$(RM) $(OBJS)
			make -C $(LIBFT_PATH) clean

fclean:		clean
			$(RM) $(NAME)
			make -C $(LIBFT_PATH) fclean

re:			fclean all

test:		gcc -I ./includes main.c libftprintf.a
			./a.out

.PHONY::	all clean fclean re test