/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_simulation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/21 16:56:02 by vchesnea          #+#    #+#             */
/*   Updated: 2016/07/05 18:45:09 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void static	print_route(t_list *route)
{
	t_room	*curr;

	route = route->content;
	while (route != NULL)
	{
		curr = route->content;
		ft_printf("{{red}}%s{{eoc}}", curr->name);
		if (route->next != NULL)
			ft_printf(" <- ");
		route = route->next;
	}
	ft_printf("\n");
}

void static	clear_marks(t_hill *hill)
{
	hill->end->visited = false;
	hill->start->visited = false;
}

int			run_simulation(t_hill *hill)
{
	t_list	*routes;

	routes = NULL;
	if (reset_simulation(hill))
		return (1);
	while (!compute_route(hill, &routes))
		clear_marks(hill);
	if (hill->flags & F_DEBUGEN)
		ft_lstiter(routes, print_route);
	return (0);
}
