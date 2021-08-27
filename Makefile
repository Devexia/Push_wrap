SRCS =	parsing/parsing.c	\
		parsing/parsing_utils.c \
		parsing/rank_stack.c \
		instructions/Pab.c	\
		instructions/Rab.c	\
		instructions/Sab.c	\
		algo/big_algo.c		\
		algo/algo.c			\
		algo/algo_utils.c



OBJS		= $(SRCS:.c=.o)

NAME		= push_swap

NAME_BONUS		= checker

LIB			= push_swap.h structure.h

RM 			= rm -f

GCCF		= gcc -Wall -Wextra -Werror #-fsanitize=address



all:		libft/libft.a  $(NAME)

$(NAME):	${OBJS} ${LIB} libft/libft.a push_swap.o
	$(GCCF) $(OBJS) push_swap.o libft/libft.a -o ${NAME}


push_swap.o	:	push_swap.c
	$(GCCF) -o $@ -c $<

bonus: libft/libft.a $(NAME) ${OBJS} ${LIB} bonus/checker.o 
	$(GCCF) $(OBJS)  bonus/checker.o libft/libft.a -o checker

bonus/checker.o	: bonus/checker.c
	$(GCCF) -o $@ -c $<

libft/libft.a : 
	${MAKE}  -C libft

%.o: %.c	${LIB} libft/libft.a
	${GCCF} -o $@ -c $< 




clean:
	@echo "${ColorRed} perfect clean"
	${MAKE}  -C libft/ fclean
	@${RM} ${OBJS} push_swap.o bonus/checker.o checker

fclean:		clean
	@${RM} ${NAME}

re:			fclean all

#===================ASCIIART===============#


.PHONY:		all clean fclean re bonus


