# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: syudai <syudai@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/10 04:46:14 by jtanaka           #+#    #+#              #
#    Updated: 2021/05/12 22:47:48 by syudai           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = tests
CC = gcc
CFLAGS = -Werror -Wall -Wextra -g

FRAMEWORK_PATH = ./../framework
FRAMEWORK_MAKE = $(MAKE) -C $(FRAMEWORK_PATH)
FRAMEWORK_LIB = $(FRAMEWORK_PATH)/libunit.a

HEADER_FILES = strlen/basic_tests.h atoi/atoi_tests.h ../framework/libunit.h
SRCS = $(shell find . -name '*.c')
OBJS = $(SRCS:.c=.o)

all: $(NAME)

test: all

$(NAME): ${HEADER_FILES} ${OBJS}
	${FRAMEWORK_MAKE}
	cp ${FRAMEWORK_LIB} ./
	${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${FRAMEWORK_LIB}

clean:
	$(FRAMEWORK_MAKE) clean
	${RM} ${OBJS}

fclean: clean
	$(FRAMEWORK_MAKE) fclean
	${RM} libunit.a ${NAME}

re: fclean all

.PHONY: all clean fclean re
