# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ael-yamo <ael-yamo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/23 19:46:50 by ael-yamo          #+#    #+#              #
#    Updated: 2022/03/29 14:41:32 by ael-yamo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CCFLAGS = -Wall -Wextra -Werror -Imlx -g
ECFLAGS = -framework OpenGL -framework AppKit -lmlx 
NAME = so_long
NAME = so_long
OBJ = checks/check_characters.o checks/check_characters2.o checks/check_walles.o checks/check.o utils/list_manipulation.o \
main/main.o parsingAndDrawing/parsing.o utils/so_long_utils.o parsingAndDrawing/drawing.o data/data.o moves/move.o moves/moves.o moves/moves2.o utils/putnbr.o\
get_next_line_SL/get_next_line.o get_next_line_SL/get_next_line_utils.o checks/check_outsiders.o

OBJ_BONUS = checks/check_characters.o checks/check_characters2.o checks/check_walles.o checks/check.o utils/list_manipulation.o \
main/main_bonus.o parsingAndDrawing/parsing.o utils/so_long_utils_bonus.o parsingAndDrawing/drawing.o data/data_bonus.o moves/move.o moves/moves.o moves/moves2.o utils/putnbr.o\
get_next_line_SL/get_next_line.o get_next_line_SL/get_next_line_utils.o checks/check_outsider_enemy.o parsingAndDrawing/destroy_p.o

all: $(NAME)

bonus : $(OBJ_BONUS)
	$(CC) $^ $(ECFLAGS) -o so_long_bonus
$(NAME) : $(OBJ)
	$(CC) $^ $(ECFLAGS) -o $@
%.o : %.c so_long.h 
	gcc $(CCFLAGS) -c $< -o $@

clean :
	rm -rf $(OBJ) $(OBJ_BONUS)

fclean : clean
	rm -rf $(NAME) so_long_bonus

re : fclean all