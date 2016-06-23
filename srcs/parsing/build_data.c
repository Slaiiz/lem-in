/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/21 16:54:02 by vchesnea          #+#    #+#             */
/*   Updated: 2016/06/21 16:54:07 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int	build_data(t_list *lst, t_hill *in)
{
	size_t			len;
	unsigned int	hash;
	t_room			*room;

	if ((len = ft_lstlen(lst)) < 1)
		return (1);
	if ((in->rooms = ft_memalloc(10 * len * sizeof(*in->rooms))) == NULL)
		return (1);
	while (lst)
	{
		room = (t_room*)lst->content;
		hash = key_to_hash(room->name, ft_strlen(room->name)) % (10 * len);
		ft_printf("Room '%s' has hash: {{red;u}}%#x{{eoc;}}\n",
			room->name, hash);
		if (room->command == COMMAND_START)
			in->start = room;
		else if (room->command == COMMAND_END)
			in->end = room;
		room->visits = 0;
		in->rooms[hash] = room;
		lst = lst->next;
	}
	in->len = len;
	return (0);
}
