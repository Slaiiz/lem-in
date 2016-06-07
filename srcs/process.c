/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 18:30:07 by vchesnea          #+#    #+#             */
/*   Updated: 2016/06/07 16:30:16 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int	process_command(const char **s, t_command *in)
{
	if (ft_seekstr(s, "end"))
		*in = COMMAND_END;
	else if (ft_seekstr(s, "start"))
		*in = COMMAND_START;
	else if (ft_seekstr(s, "firepit"))
		*in = COMMAND_FIREPIT;
	else if (ft_seekstr(s, "wormwhole"))
		*in = COMMAND_WORMHOLE;
	else if (ft_seekstr(s, "deathsquad"))
		*in = COMMAND_DEATHSQUAD;
	else
		return (1);
	return (!ft_seekstr(s, "\n"));
}

int	process_comment(const char **s)
{
	while (**s != '\0' && **s != '\n')
		++*s;
	return (!ft_seekstr(s, "\n"));
}

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

int	process_node(const char **s, t_anthill *in)
{
	const char		*tmp;
	t_list			*new;
	t_room			*node_a;
	t_room			*node_b;

	tmp = *s - 1;
	while (*++tmp != '-')
		if (*tmp == '\0' || *tmp == '\n')
			return (1);
	node_a = in->rooms[key_to_hash(*s, (size_t)(tmp - *s)) % (10 * in->len)];
	*s = tmp + 1;
	while (*++tmp != '\n')
		if (*tmp == '\0')
			return (1);
	node_b = in->rooms[key_to_hash(*s, (size_t)(tmp - *s)) % (10 * in->len)];
	if ((new = ft_lstnew(node_b, sizeof(node_b))) == NULL)
		return (1);
	ft_lstadd(&node_a->nodes, new);
	if ((new = ft_lstnew(node_a, sizeof(node_a))) == NULL)
		return (1);
	ft_lstadd(&node_b->nodes, new);
	ft_printf("Created linkage\n");
	*s = ++tmp;
	return (0);
}
