# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: knfonda <knfonda@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/28 09:04:40 by knfonda           #+#    #+#              #
#    Updated: 2020/11/16 11:16:11 by knfonda          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= display_int.c ft_init.c ft_print_utils.c\
		ft_printf.c ft_putchar_len.c ft_reinit.c display_char.c display_str.c\
		display_uint.c display_proc.c ft_putnbr.c display_x.c\
		ft_itoa_hex.c display_xx.c display_p.c ft_itoa_hexu.c\
		ft_putnbru.c ft_parser.c

OBJS	= $(SRCS:.c=.o)

NAME	= libftprintf.a

GCC		= gcc

RM		= rm -f

AR		= ar rcs

CFLAGS	= -Wall -Werror -Wextra

all:		$(NAME)

.c.o:		
			$(GCC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
			$(AR) $(NAME) $(OBJS)

clean:		
			$(RM) $(OBJS) $(B_OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean $(NAME)

.PHONY:		all clean fclean re bonus
