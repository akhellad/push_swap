
# VARIABLES #

HEAD_DIR =	./includes

SRC_DIR	=	./src/

OBJ_DIR	=	./compilated_src/

RM = rm -rf

CC = gcc

CFLAGS = -Wall -Wextra -Werror

# FICHIERS A COMPILER #

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

SRCS		=	$(SRC)

# COMPILER LES SOURCES #

OBJS 		=	$(SRCS:%.c=$(OBJ_DIR)%.o)

NAME 		=	push_swap

## REGLES ##

all:			$(NAME)

debug:			CFLAGS += -g3 -fsanitize=address
debug:			all

# REGLES DES VARIABLES #

$(NAME):		$(OBJS)
				$(CC) $(CFLAGS) -I $(HEAD_DIR) $(OBJS) -o $(NAME)

# REGLES POUR LES FICHIERS COMPILÉS #

$(OBJS):		| $(OBJ_DIR)


$(OBJ_DIR)%.o: $(SRC_DIR)%.c
				$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
				mkdir $(OBJ_DIR)

clean:
				$(RM) $(OBJ_DIR)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

# PHONY #

.PHONY:			all clean fclean re