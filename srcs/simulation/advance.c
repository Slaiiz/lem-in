/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   advance.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 18:46:18 by vchesnea          #+#    #+#             */
/*   Updated: 2016/06/28 18:51:05 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int	advance(t_list **route, t_room **out)
{
	t_room	*next;
	t_list	*nodes;

	nodes = (*out)->nodes;
	while (nodes != NULL)
	{
		next = nodes->content;
		if (!next->visited)
		{
			if (mark_visit(route, (*out)))
				exit(1);
			*out = next;
			return (0);
		}
		nodes = nodes->next;
	}
	return (1);
}
