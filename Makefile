NAME	=	so_long

B_NAME	=	so_long_bonus

SRC		= 	so_long.c \
			get_next_line.c \
			get_next_line_utils.c \
			move.c \
			check_argc.c \
			parsing_map.c \
			error.c \
			put_icon.c

B_SRC	=	bonus/so_long_bonus.c \
           	bonus/get_next_line_bonus.c \
            bonus/get_next_line_utils_bonus.c \
            bonus/move_bonus.c \
            bonus/check_argc_bonus.c \
            bonus/parsing_map_bonus.c \
            bonus/error_bonus.c \
            bonus/put_icon_bonus.c \
            bonus/ft_itoa_mod_bonus.c \
            bonus/move_and_put_bonus.c

OBJ		=	$(SRC:.c=.o)

B_OBJ	=	$(B_SRC:.c=.o)

CFLAGS	=	-Werror -Wextra -Wall

all		: $(NAME)


$(NAME) : $(OBJ)
	gcc $(SRC) -o $(NAME) -lmlx -framework OpenGL -framework AppKit -I


bonus	:	$(B_OBJ)
	gcc $(B_SRC) -o $(B_NAME) -lmlx -framework OpenGL -framework AppKit -I

%.o		: %.c
	gcc $(CFLAGS) -c $< -o $@

clean	:
	rm -f *.o
	rm -f bonus/*.o

fclean	: clean
	rm -f $(NAME) $(B_NAME)

re		: fclean all


.PHONY	: all clean fclean re bonus