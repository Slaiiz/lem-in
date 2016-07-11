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

int static	store_route(t_list *route, t_list **out)
{
	t_list	*new;

	if ((new = ft_lstnew(route, sizeof(*route))) == NULL)
		return (1);
	ft_lstadd(out, new);
	return (0);
}

int			compute_route(t_hill *hill, t_room *curr, t_list **out)
{
	t_list	*route;

	if (hill->flags & F_DEBUGEN)
		ft_printf("Computing new route.\n");
	route = NULL;
	while (curr != hill->end)
		if (advance(hill, &route, &curr))
			if (step_back(hill, &route, &curr))
			{
				if (hill->flags & F_DEBUGEN)
					ft_printf("Giving up.\n");
				ft_lstdel(&route, NULL);
				return (1);
			}
	if (hill->flags & F_OPT_AGGR)
		optimize_route(hill, &route);
	store_route(route, out);
	if (hill->flags & F_DEBUGEN)
		ft_printf("Done computing a route.\n");
	return (0);
}
