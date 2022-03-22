/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-yamo <ael-yamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 10:59:52 by ael-yamo          #+#    #+#             */
/*   Updated: 2022/03/22 13:28:26 by ael-yamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#include "list.h"
#include "get_next_line_SL/get_next_line.h"

/* ********* ********* ********** */
/* ********* CHECK MAP ********** */
/* ********* ********* ********** */

/* _________ CHECK CHARS _________*/

int check_P(t_list *list);
int check_C(t_list *list);
int check_E(t_list *list);
int	check_outsiders(t_list *list);
int	check_if_rctnglr(t_list *list);

/* _________ CHECK WLLES _________*/

int check_hrsntl(char *first, char *last);
int	check_vrtcl(t_list *list);
int	check(int fd);

/* ********* ************* ********** */
/* ********* SO LONG UTILS ********** */
/* ********* ************* ********** */

size_t	str_len(const char *s);
t_list	*parsing(t_list **last, int fd);
void	exit_game(t_list **list);

#endif