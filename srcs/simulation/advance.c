/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   advance.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 18:46:18 by vchesnea          #+#    #+#             */
/*   Updated: 2016/06/28 18:51:05 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int	advance(t_hill *hill, t_list **route, t_room **out)
{
	t_list	*new;
	t_room	*next;
	t_list	*nodes;

	nodes = (*out)->nodes;
	while (nodes != NULL)
	{
		next = nodes->content;
		if (!next->visited)
		{
			if (hill->flags & F_DEBUGEN)
				ft_printf(" Advancing to '%s'\n", next->name);
			if ((new = ft_lstnew(next, sizeof(*next))) == NULL)
				return (1);
			(*out)->visited = true;
			ft_lstadd(route, new);
			*out = next;
			return (0);
		}
		nodes = nodes->next;
	}
	return (1);
}
