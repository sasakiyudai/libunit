NAME = libunit.a
CC = gcc
CFLAGS = -Werror -Wall -Wextra -g

HEADER_FILES = libunit.h
SRCS = exit_fatal.c launch_tests.c load_test.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): ${HEADER_FILES} ${OBJS}
	$(LIBFT_MAKE)
	ar rc ${NAME} ${OBJS}

clean:
	$(LIBFT_MAKE) clean
	${RM} ${OBJS}

fclean: clean
	$(LIBFT_MAKE) fclean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
