/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_visits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/11 18:41:43 by vchesnea          #+#    #+#             */
/*   Updated: 2016/07/11 18:41:46 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		set_visits(t_list *route, bool state)
{
	while (route != NULL)
	{
		((t_room*)route->content)->visited = state;
		route = route->next;
	}
}
