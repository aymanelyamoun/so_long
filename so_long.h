/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-yamo <ael-yamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 10:59:52 by ael-yamo          #+#    #+#             */
/*   Updated: 2022/03/22 11:29:34 by ael-yamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

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
int	check();

/* ********* ************* ********** */
/* ********* SO LONG UTILS ********** */
/* ********* ************* ********** */

t_list	*parsing(t_list **last);
void	exit_game(t_list **list);