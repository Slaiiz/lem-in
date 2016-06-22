/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_route.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/22 18:38:32 by vchesnea          #+#    #+#             */
/*   Updated: 2016/06/22 18:46:34 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int	mark_visit(t_list **out, t_room *curr)
{
	t_list	*new;

	if ((new = ft_lstnew(curr, sizeof(*curr))) == NULL)
		return (1);
	ft_lstadd(out, new);
	++curr->visits;
	return (0);
}

static int	find_exit(t_room *curr, t_room **out)
{
	t_room	*next;
	t_list	*nodes;

	nodes = curr->nodes;
	while (nodes != NULL)
	{
		next = nodes->content;
		if (next->visits == 0)
		{
			*out = next;
			return (0);
		}
		nodes = nodes->next;
	}
	return (1);
}

static void	delete_exit(t_room *room, size_t size)
{
	*room = NULL;
}

/*
** FIXME: ft_lstdelone incorrect
*/

int			compute_route(t_anthill *hill, t_list **out)
{
	t_room	*curr;
	t_room	*next;

	*out = NULL;
	curr = hill->start;
	while (curr != hill->end)
	{
		if (mark_visit(out, curr))
			return (1);
		if (find_exit(curr, &next))
		{
			ft_printf("Found no exit, falling back.\n");
			ft_lstdelone(out, delete_exit);
		}
	}
}
