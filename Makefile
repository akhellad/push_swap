SRCS		=	./srcs

DIR			=	./

RM			=	rm -rf

CHECKER		=	checker

PUSH_SWAP	=	push_swap

# **************************************************************************** #

all:			$(CHECKER) $(PUSH_SWAP)

$(CHECKER):	
				$(MAKE) -C $(SRCS)/$(CHECKER) MAKEFLAGS=
				cp -rf $(SRCS)/$(CHECKER)/$(CHECKER) $(DIR)/$(CHECKER)

$(PUSH_SWAP):	
				$(MAKE) -C $(SRCS)/$(PUSH_SWAP)/ MAKEFLAGS=
				cp -rf $(SRCS)/$(PUSH_SWAP)/$(PUSH_SWAP) ./$(PUSH_SWAP)

# OBLIGATORY PART #

clean:
				make clean -C $(SRCS)/$(CHECKER)
				make clean -C $(SRCS)/$(PUSH_SWAP)

fclean:	
				make fclean -C $(SRCS)/$(CHECKER)
				make fclean -C $(SRCS)/$(PUSH_SWAP)
				$(RM) $(CHECKER)
				$(RM) $(PUSH_SWAP)

re:				fclean all

.PHONY:			all clean fclean checker push_swap
