CC = cc
CCFLAGS = -Wall -Wextra -Werror -Imlx
ECFLAGS = -framework OpenGL -framework AppKit -lmlx 
NAME = so_long
OBJ = test.o

all: $(NAME)

$(NAME) : $(OBJ)
	$(CC) $^ $(ECFLAGS) -o $@

%.o : %.c
	gcc $(CCFLAGS) -c $< -o $@

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all