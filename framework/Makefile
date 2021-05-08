NAME = libunit.a
CC = gcc
CFLAGS = -Werror -Wall -Wextra -g

LIBFT_PATH = ./../libft
LIBFT_MAKE = $(MAKE) -C $(LIBFT_PATH)
LIBFT_LIB = $(LIBFT_PATH)/libft.a

HEADER_FILES = libunit.h
SRCS = exit_fatal.c launch_tests.c load_test.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): ${HEADER_FILES} ${OBJS}
	$(LIBFT_MAKE)
	cp $(LIBFT_LIB) $(NAME)
	ar rcs $(NAME) $(OBJS)

clean:
	$(LIBFT_MAKE) clean
	${RM} ${OBJS}

fclean: clean
	$(LIBFT_MAKE) fclean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
