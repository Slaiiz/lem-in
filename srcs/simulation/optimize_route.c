/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_route.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/05 15:11:09 by vchesnea          #+#    #+#             */
/*   Updated: 2016/07/05 15:11:10 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void static	validate(t_hill *hill, t_list *save, t_list **out)
{
	if (hill->flags & F_DEBUGEN)
		ft_printf("Found one optimization.\n");
	ft_printf("{{green}}%d{{eoc}}\n", ft_lstlen(save));
	ft_lstdel(out, NULL);
	*out = save;
}

void static	reject(t_hill *hill)
{
	if (hill->flags & F_DEBUGEN)
		ft_printf("Found no better solution.\n");
}

int			optimize_route(t_hill *hill, t_list **route)
{
	t_list	*save;
	t_room	*curr;

	ft_printf("{{red}}%d{{eoc}}\n", ft_lstlen((*route)->content));
	if (hill->flags & F_DEBUGEN)
		ft_printf("Optimizing route ... ");
	save = ft_lstdup(*route);
	while (true)
	{
		if (step_back(&save, &curr))
			break ;
		while (curr != hill->end)
		{
			if (advance(&save, &curr))
				if (step_back(&save, &curr))
					break ;
		}
		if (curr == hill->end)
		{
			validate(hill, save, route);
			return (0);
		}
	}
	reject(hill);
	return (1);
}
