/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_route.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/22 18:38:32 by vchesnea          #+#    #+#             */
/*   Updated: 2016/07/05 18:44:37 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void static	store_route(t_list *route, t_list **out)
{
	t_list	*new;

	if ((new = ft_lstnew(route, sizeof(*route))) == NULL)
		exit(1);
	ft_lstadd(out, new);
}

int			compute_route(t_hill *hill, t_list **out)
{
	t_room	*curr;
	t_list	*route;

	route = NULL;
	curr = hill->start;
	mark_visit(&route, curr);
	if (step_back(&route, &curr))
		exit(1);
	while (curr != hill->end)
		if (advance(&route, &curr))
			if (step_back(&route, &curr))
				return (1);
	// optimize_route(hill, &route);
	store_route(route, out);
	ft_printf("Route ok\n");
	return (0);
}
