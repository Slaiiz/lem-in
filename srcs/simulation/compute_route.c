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

int static	mark_visit(t_list **out, t_room *curr)
{
	t_list	*new;

	if ((new = ft_lstnew(curr, sizeof(*curr))) == NULL)
		return (1);
	ft_lstadd(out, new);
	++curr->visits;
	return (0);
}

int static	find_exit(t_room *curr, t_room **out)
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

int static	store_route(t_list *route, t_list **out)
{
	t_list	*new;

	if ((new = ft_lstnew(route, sizeof(*route))) == NULL)
		return (1);
	ft_lstadd(out, new);
	return (0);
}

int			compute_route(t_hill *hill, t_list **out)
{
	t_room	*curr;
	t_room	*next;
	t_list	*route;

	route = NULL;
	curr = hill->start;
	while (curr != hill->end)
	{
		if (find_exit(curr, &next))
		{
			if (route == NULL)
				return (1);
			ft_lstdelone(&route, NULL);
			curr = route->content;
			continue ;
		}
		if (mark_visit(&route, curr))
			return (1);
		curr = next;
	}
	if (store_route(route, out))
		return (1);
	return (0);
}
