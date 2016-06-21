/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_room.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/21 16:55:40 by vchesnea          #+#    #+#             */
/*   Updated: 2016/06/21 16:55:44 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int	process_room(const char **s, t_command command, t_list **in)
{
	const char	*tmp;
	t_list		*item;
	t_room		*room;

	tmp = *s - 1;
	while (*++tmp != ' ')
		if (*tmp == '\0' || *tmp == '\n')
			return (1);
	if ((size_t)(tmp - *s) < 1 || (room = malloc(sizeof(*room))) == NULL)
		return (1);
	room->nodes = NULL;
	room->command = command;
	room->name = ft_strsub(*s, 0, (size_t)(tmp++ - *s));
	if (ft_expect(&tmp, "$nw $nw\n", &room->x, &room->y))
		return (1);
	ft_printf("New room:\n- Name = '%s'\n- X = %d\n- Y = %d\n",
		room->name, room->x, room->y);
	if ((item = ft_lstnew(room, sizeof(*room))) == NULL)
		return (1);
	ft_lstadd(in, item);
	*s = tmp;
	return (0);
}
