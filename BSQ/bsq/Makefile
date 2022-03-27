# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tde-nico <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/13 09:14:25 by tde-nico          #+#    #+#              #
#    Updated: 2021/12/14 14:52:42 by tde-nico         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ./srcs/main.c ./srcs/map.c ./srcs/parse.c ./srcs/solve.c ./srcs/utils.c
OBJS	= ${SRCS:.c=.o}
INCS	= includes
NAME	= bsq
CC		= gcc
RM		= rm -f
FLAGS	= -Wall -Wextra -Werror -g

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o} -I ${INCS}

${NAME}: ${OBJS}
	${CC} ${FLAGS} ${OBJS} -o ${NAME}

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re .c.o test
