/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_simulation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/21 16:56:02 by vchesnea          #+#    #+#             */
/*   Updated: 2016/06/21 17:21:53 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void static	print_route(t_list *route)
{
	t_room	*curr;

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
	hill->end->visits = 0;
	hill->start->visits = 0;
}

void static debug(t_list *lst)
{
	ft_printf("%p\n%d\n", lst, ft_lstlen(lst));
}

int			run_simulation(t_hill *hill, unsigned short flags)
{
	t_list	*routes;
	t_room	*room;

	routes = NULL;
	if (reset_simulation(hill))
		return (1);
	while (!compute_route(hill, &routes))
		clear_marks(hill);
	if (flags & F_DEBUGEN)
		ft_lstiter(routes, debug);
	return (0);
}
