/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/21 16:54:02 by vchesnea          #+#    #+#             */
/*   Updated: 2016/07/05 14:28:41 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void static	attribute_slot(t_hill *hill, t_room *room)
{
	unsigned int	hash;

	hash = key_to_hash(room->name, ft_strlen(room->name)) % (10 * hill->len);
	if (hill->flags & F_DEBUGEN)
		ft_printf("Room '%s' has hash: {{red;u}}%#x{{eoc;}}\n",
			room->name, hash);
	if (room->command == COMMAND_START)
		hill->start = room;
	else if (room->command == COMMAND_END)
		hill->end = room;
	room->visited = false;
	hill->rooms[hash] = room;
}

int			build_data(t_list *lst, t_hill *in)
{
	if ((in->len = ft_lstlen(lst)) < 1)
		return (1);
	if ((in->rooms = ft_memalloc(10 * in->len * sizeof(*in->rooms))) == NULL)
		return (1);
	while (lst != NULL)
	{
		attribute_slot(in, (t_room*)lst->content);
		lst = lst->next;
	}
	return (0);
}
