# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ael-yamo <ael-yamo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/23 19:46:50 by ael-yamo          #+#    #+#              #
#    Updated: 2022/03/26 15:03:13 by ael-yamo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CCFLAGS = -Wall -Wextra -Werror -Imlx -g
ECFLAGS = -framework OpenGL -framework AppKit -lmlx 
NAME = so_long
OBJ = check_characters.o check_characters2.o check_walles.o check.o list_manipulation.o \
main.o parsing.o so_long_utils.o drawing.o data.o moves.o moves2.o putnbr.o\
get_next_line_SL/get_next_line.o get_next_line_SL/get_next_line_utils.o 

all: $(NAME)

$(NAME) : $(OBJ)
	$(CC) $^ $(ECFLAGS) -o $@
test : test.o
	$(CC) $^ $(ECFLAGS) -o $@
%.o : %.c so_long.h 
	gcc $(CCFLAGS) -c $< -o $@

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all