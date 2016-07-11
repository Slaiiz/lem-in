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

void static	free_resources(t_list **routes)
{
	t_list	*curr;

	curr = *routes;
	while (curr != NULL)
	{
		free_route((t_list**)&curr->content);
		curr = curr->next;
	}
	ft_lstdel(routes, NULL);
}

int			run_simulation(t_hill *hill)
{
	t_list	*routes;

	routes = NULL;
	if (reset_simulation(hill))
		return (1);
	while (!compute_route(hill, hill->start, &routes))
		hill->end->visited = false;
	if (hill->flags & F_DEBUGEN)
		ft_lstiter(routes, print_route);
	free_resources(&routes);
	return (0);
}
