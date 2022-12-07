SRCS = init_tab.c main.c moove.c moove2.c
INCL = printf/libftprintf.a libft/libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
HEADER = ft_printf.h libft.h pushswap.h

all:
	${CC} ${SRCS} ${INCL}
	
	
clean:
	${RM} a.out

fclean:	clean
	${RM} ${NAME}

re: fclean all

.PHONY: re all clean fclean 