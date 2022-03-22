/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-yamo <ael-yamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 13:09:58 by ael-yamo          #+#    #+#             */
/*   Updated: 2022/03/22 14:53:09 by ael-yamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H

#include <unistd.h>
struct s_list
{
	struct s_list	*next;
	struct s_list	*prev;
	char			*str;
};

typedef struct s_list t_list;

t_list *add_at_end(t_list **list, char **str);
void	free_list(t_list **list);

#endif