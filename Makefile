CC = cc
CCFLAGS = -Wall -Wextra -Werror -Imlx
ECFLAGS = -framework OpenGL -framework AppKit -lmlx 
NAME = so_long
OBJ = check_characters.o check_characters2.o check_walles.o check.o list_manipulation.o \
main.o parsing.o so_long_utils.o \
get_next_line_SL/get_next_line.o get_next_line_SL/get_next_line_utils.o

all: $(NAME)

$(NAME) : $(OBJ)
	$(CC) $^ $(ECFLAGS) -o $@

%.o : %.c so_long.h 
	gcc $(CCFLAGS) -c $< -o $@

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all