# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tde-nico <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/11 09:47:33 by tde-nico          #+#    #+#              #
#    Updated: 2021/12/11 12:49:08 by vcirinei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ./srcs/file.c
OBJS	= ${SRCS:.c=.o}
INCS	= include
NAME	= rush-02
CC		= gcc
RM		= rm -f
FLAGS	= -Wall -Wextra -Werror

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o} -I${INCS}

${NAME}: ${OBJS}
	${CC} ${FLAGS} ${OBJS} -o ${NAME} -I $(INCS)

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

norm:
	norminette -R CheckForbiddenSourceHeader */*.[ch]

re: fclean all

test: re
	./${NAME} 42 | cat -e
	./${NAME} 0 | cat -e
	./${NAME} 10.4 | cat -e
	./${NAME} 100000 | cat -e
	./${NAME} numbers.dict 20 | cat -e
	./${NAME} custom.dict 20 | cat -e

.PHONY: all clean fclean re .c.o test norm
