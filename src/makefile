
# VARIABLES #

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

# COMPILED_SOURCES #

OBJS 		=	$(SRCS:%.c=$(DIR_OBJS)%.o)

NAME 		=	push_swap


# **************************************************************************** #

## RULES ##

all:			$(NAME)

debug:			CC_FLAGS += -g3 -fsanitize=address
debug:			all

# VARIABLES RULES #

$(NAME):		$(OBJS)
				$(CC) $(CC_FLAGS) -I $(DIR_HEADERS) $(OBJS) -o $(NAME)

# COMPILED_SOURCES RULES #

$(OBJS):		| $(DIR_OBJS)


$(DIR_OBJS)%.o: $(DIR_SRCS)%.c
				$(CC) $(CC_FLAGS) -I $(DIR_HEADERS) -c $< -o $@

$(DIR_OBJS):
				mkdir $(DIR_OBJS)


# OBLIGATORY PART #

clean:
				$(RM) $(DIR_OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

# PHONY #

.PHONY:			all clean fclean re norm
