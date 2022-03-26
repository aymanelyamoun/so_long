# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ael-yamo <ael-yamo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/23 19:46:50 by ael-yamo          #+#    #+#              #
#    Updated: 2022/03/26 17:47:22 by ael-yamo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CCFLAGS = -Wall -Wextra -Werror -Imlx -g
ECFLAGS = -framework OpenGL -framework AppKit -lmlx 
NAME = so_long
NAME = so_long
OBJ = check_characters.o check_characters2.o check_walles.o check.o list_manipulation.o \
main.o parsing.o so_long_utils.o drawing.o data.o move.o moves.o moves2.o putnbr.o\
get_next_line_SL/get_next_line.o get_next_line_SL/get_next_line_utils.o check_outsiders.o

OBJ_BONUS = check_characters.o check_characters2.o check_walles.o check.o list_manipulation.o \
main_bonus.o parsing.o so_long_utils.o drawing.o data_bonus.o move.o moves.o moves2.o putnbr.o\
get_next_line_SL/get_next_line.o get_next_line_SL/get_next_line_utils.o check_outsider_enemy.o

all: $(NAME)

bonus : $(OBJ_BONUS)
	$(CC) $^ $(ECFLAGS) -o so_long_bonus
$(NAME) : $(OBJ)
	$(CC) $^ $(ECFLAGS) -o $@
test : test.o
	$(CC) $^ $(ECFLAGS) -o $@
%.o : %.c so_long.h 
	gcc $(CCFLAGS) -c $< -o $@

clean :
	rm -rf $(OBJ) $(OBJ_BONUS)

fclean : clean
	rm -rf $(NAME) so_long_bonus

re : fclean all