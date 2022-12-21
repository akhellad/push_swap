SRC = 	main.c \
		push_swap.c \
		init_piles.c \
		pile.c \
		operations.c \
		utils.c \
		conditions.c \
		free_pile.c \
		resolution.c \
		bruteforce_op.c \
		bruteforce.c \
		sort_pile.c \
		directions.c \
		move.c \
		ft_atoi.c \
		ft_strdup.c
SRCS = $(SRC)
OBJS = $(SRCS:%.c=%.o)
NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
HEADER = pushswap.h

all: ${NAME}

${NAME}:	${OBJS}
			${CC} ${CFLAGS} ${OBJS} -g3 -fsanitize=address
	
clean:
	${RM} ${OBJS}

fclean:	clean
	${RM} ${NAME}

re: fclean all

.PHONY: re all clean fclean 