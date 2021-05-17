# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/10 15:45:06 by jfrancis          #+#    #+#              #
#    Updated: 2021/05/16 11:20:26 by jfrancis         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIBFT = libft.a

CC = gcc
CFLAGS = -g3 -Wall -Wextra -Werror
FILES = ft_printf.c set_format.c ft_putchar.c ft_putstr.c set_flags.c \
		check_params.c get_char.c define_number.c define_width.c \
		get_wildcard_value.c get_string.c print_fill.c get_integer.c \
		negative_case.c get_pointer.c get_hex.c hextoa.c hex_size.c \
		ft_putnbr.c left_align_fill.c right_align_fill.c get_u_int.c
OBJS = $(FILES:.c=.o)
RM = rm -f
LIBFT_PATH = ./libft
INCLUDES = ./includes

%.o: %.c
			$(CC) -c -I $(INCLUDES) -o $@ $< $(CFLAGS)

$(NAME):	$(OBJS) $(LIBFT_PATH)
			$(CC) -I $(INCLUDES) $(FLAGS) -c $(FILES)
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

.PHONY::	all clean fclean re test