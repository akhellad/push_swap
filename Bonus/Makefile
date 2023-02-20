# VARIABLES #

HEAD_DIR =	./includes

SRC_DIR	=	./src/

OBJ_DIR	=	./compilated_src/

RM = rm -rf

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC 		= 	checker.c \
				directions.c \
				free_pile.c \
				init_piles.c \
				get_next_line.c \
				get_next_line_utils.c \
				operations.c \
				ft_strdup.c \
				ft_atoi.c

SRCS		=	$(SRC)

OBJS 		=	$(SRCS:%.c=$(OBJ_DIR)%.o)

NAME 		=	checker

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