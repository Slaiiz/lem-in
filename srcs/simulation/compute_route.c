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

static int	store_route(t_list *route, t_list ***routes)
{
	t_list	*new;

	if (ft_lstnew(route, sizeof(*route)))
		return (1);
	ft_lstadd((t_list**)routes, route);
	return (0);
}

int			compute_route(t_hill *hill, t_list ***out)
{
	t_room	*curr;
	t_room	*next;
	t_list	*route;

	route = NULL;
	curr = hill->start;
	if (mark_visit(&route, curr))
		return (1);
	while (curr != hill->end)
	{
		if (find_exit(curr, &next))
		{
			ft_lstdelone(&route, NULL);
			if (route == NULL)
				return (1);
			curr = route->content;
			continue ;
		}
		if (mark_visit(&route, next))
			return (1);
		curr = next;
	}
	if (store_route(route, out))
		return (1);
	return (0);
}
