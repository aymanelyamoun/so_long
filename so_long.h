/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-yamo <ael-yamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 10:59:52 by ael-yamo          #+#    #+#             */
/*   Updated: 2022/03/26 19:07:56 by ael-yamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# include "list.h"
# include "get_next_line_SL/get_next_line.h"
# include <mlx.h>

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		img_width;
	int		img_height;
	int		x_positon;
	int		y_positon;
}		t_img_data;

typedef struct s_images
{
	t_img_data	wall;
	t_img_data	player;
	t_img_data	collectable;
	t_img_data	exit;
	t_img_data	space;
	t_img_data	enemy;
	int			x;
	int			y;
}			t_images_data;

typedef struct s_data
{
	void			*mlx;
	void			*win;
	int				win_x;
	int				win_y;
	t_images_data	images;
	t_list			*map;
	int				moves;
	int				collectable;
}	t_data;

void	ft_putnbr(int new_nb);
/* ********* ********* ********** */
/* ********* CHECK MAP ********** */
/* ********* ********* ********** */
int		haschar(char *str, char c);
/* _________ CHECK CHARS _________*/

int		check_p(t_list *list);
int		check_c(t_list *list);
int		check_e(t_list *list);
int		check_outsiders(t_list *list);
int		check_if_rctnglr(t_list *list);

/* _________ CHECK WLLES _________*/

int		check_hrsntl(char *first, char *last);
int		check_vrtcl(t_list *list);
t_list	*check(int fd);

/* ********* ************* ********** */
/* ********* SO LONG UTILS ********** */
/* ********* ************* ********** */

size_t	str_len(const char *s);
t_list	*parsing(t_list **last, int fd);
void	exit_game(t_list **list);
void	end_game(t_data *data);
int		check_left_C(t_list *list);
void	game_over(t_data *data);

/* ********* ************* ********** */
/* ********* *** MOVES *** ********** */
/* ********* ************* ********** */

void	move_up(t_data *data);
void	move_down(t_data *data);
void	move_right(t_data *data);
void	move_left(t_data *data);
int		moves(int key, t_data *data);
/**/

/* ********* ************* ********** */
/* ********* *** DATA  *** ********** */
/* ********* ************* ********** */

void	init_imgs(t_data *data);
void	set_data(t_data *data, t_list *map);
void	destroy(t_data *data);

/* ********* ************* ********** */
/* ********* ** DRAWING ** ********** */
/* ********* ************* ********** */

void	draw(t_list *map, t_data *data);

#endif