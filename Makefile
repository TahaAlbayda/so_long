SRCS =  $(wildcard src/*.c gnl/*.c)

OBJS				= ${SRCS:.c=.o}

NAME				= so_long

LIBFTNAME 			= ./ft_printf/libftprintf.a

CC					= cc

RM					= rm -f

LIBFTDIR			= ./ft_printf

CFLAGS				= -Wall -Wextra -Werror -Iincludes

MLXFLAGS			= -L ./mlx_linux -lmlx  -L/usr/lib -lXext -lX11 -Imlx_linux -lm -lz 

LIBMXLDIR			= ./mlx_linux

LIBMXLNAME 			= ./mlx_linux/libmlx.a

all:				${NAME}

%.o: %.c
					${CC} ${CFLAGS} -I/usr/include -Imlx_linux -O3 -c $< -o $@


$(NAME):$(OBJS)
		make -C $(LIBFTDIR)
		make -C $(LIBMXLDIR)
		$(CC) $(CFLAGS) $(OBJS) $(MLXFLAGS) -o $(NAME)  $(LIBFTNAME) $(LIBMXLNAME)


clean:
					${RM} ${OBJS}
					@cd $(LIBFTDIR) && make clean

fclean:				clean
					${RM} ${NAME}
					@cd $(LIBFTDIR) && make fclean

re:					fclean all

.PHONY:				all bonus clean fclean re