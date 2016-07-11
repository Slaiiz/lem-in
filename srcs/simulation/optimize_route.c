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

int	static validate(t_hill *hill, t_list **in, t_list **out)
{
	if (hill->flags & F_DEBUGEN)
		ft_printf("Optimization validated.\n");
	free_route(out);
	*out = *in;
	return (0);
}

int static	reject(t_hill *hill, t_list **in, t_list **out)
{
	if (hill->flags & F_DEBUGEN)
		ft_printf("Optimization rejected.\n");
	set_visits(*in, false);
	set_visits(*out, true);
	free_route(in);
	return (1);
}

int			optimize_route(t_hill *hill, t_list **out)
{
	t_list	*save;
	t_room	*curr;
	int		steps;

	if (hill->flags & F_DEBUGEN)
		ft_printf("Optimizing route ...\n");
	if ((save = ft_lstdup(*out)) == NULL)
		return (1);
	set_visits(*out, false);
	step_back(hill, &save, &curr);
	steps = 1;
	while (curr != hill->end)
	{
		if (steps > 0 && !advance(hill, &save, &curr) && steps--)
			continue ;
		if (!step_back(hill, &save, &curr) && ++steps)
			continue ;
		return (reject(hill, &save, out));
	}
	return (validate(hill, &save, out));
}
