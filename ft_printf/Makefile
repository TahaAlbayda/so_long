SRCS				= ft_printf.c putlchr.c putlhex.c putlnbr.c putlptr.c putlstr.c putlunbr.c

OBJS				= ${SRCS:.c=.o}

NAME				= libftprintf.a

LIBFTNAME 			= libft.a

CC					= cc

RM					= rm -f

LIBFTDIR			= ./libft

CFLAGS				= -Wall -Wextra -Werror 

all:				${NAME}

%.o: %.c
					${CC} ${CFLAGS} -c $< -o $@


$(NAME):			${OBJS}
					@make -C $(LIBFTDIR)
					@cp $(LIBFTDIR)/$(LIBFTNAME) $(NAME)
					@ar -rcs ${NAME} ${OBJS}


clean:
					${RM} ${OBJS}
					@cd $(LIBFTDIR) && make clean

fclean:				clean
					${RM} ${NAME}
					@cd $(LIBFTDIR) && make fclean

re:					fclean all

.PHONY:				all bonus clean fclean re
