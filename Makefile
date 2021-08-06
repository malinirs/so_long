NAME   = 	so_long

SRC    = 	so_long.c \
			get_next_line.c \
			get_next_line_utils.c \
			move.c \
			check_argc.c \
			parsing_map.c

OBJ    = 	$(SRC:.c=.o)

CFLAGS =	-Werror -Wextra -Wall

all		: $(NAME)


$(NAME) : $(OBJ)
	gcc $(SRC) -o $(NAME) -lmlx -framework OpenGL -framework AppKit -I

%.o		: %.c
	gcc $(CFLAGS) -c $< -o $@

clean	:
	rm -f *.o

fclean	: clean
	rm -f $(NAME)

re		: fclean all


.PHONY	: all clean fclean re