/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 18:46:23 by vchesnea          #+#    #+#             */
/*   Updated: 2016/06/28 18:53:01 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int	step_back(t_hill *hill, t_list **route, t_room **out)
{
	if (*route == NULL)
	{
		*out = NULL;
		return (1);
	}
	if (hill->flags & F_DEBUGEN)
		ft_printf(" Returning from '%s'\n",
			((t_room*)(*route)->content)->name);
	ft_lstdelone(route, NULL);
	*out = (*route)->content;
	return (0);
}
