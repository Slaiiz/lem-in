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

static void	print_route(t_list *route)
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

int			run_simulation(t_hill *hill, unsigned short flags)
{
	t_list	**routes;

	if (reset_simulation(hill))
		return (1);
	while (!compute_route(hill, &routes))
		continue ;
	if (flags & F_DEBUGEN)
	{
		ft_printf("Got %d routes\n", ft_lstlen((t_list*)routes));
		ft_lstiter((t_list*)routes, print_route);
	}
	return (0);
}
