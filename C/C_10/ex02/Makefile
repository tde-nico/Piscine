# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tde-nico <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/07 14:50:34 by tde-nico          #+#    #+#              #
#    Updated: 2021/12/15 08:26:46 by tde-nico         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ./srcs/main.c ./srcs/extra.c ./srcs/error.c
INCS	= includes
OBJS	= ${SRCS:.c=.o}
NAME	= ft_tail
CC		= gcc
RM		= rm -f
FLAGS	= -Wall -Wextra -Werror -I ${INCS}

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o} -I ${INCS}

${NAME}: ${OBJS}
	${CC} ${FLAGS} ${OBJS} -o ${NAME}

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

norm:
	norminette -R CheckForbiddenSourceHeader */*.[ch]

re: fclean all

.PHONY: all clean fclean re .c.o
