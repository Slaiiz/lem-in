/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 18:30:07 by vchesnea          #+#    #+#             */
/*   Updated: 2016/06/03 18:03:29 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int	process_command(const char **s, t_command *in)
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

static int	process_comment(const char **s)
{
	while (**s != '\0' && **s != '\n')
		++*s;
	return (!ft_seekstr(s, "\n"));
}

static int	process_room(const char **s, t_command command, t_list **in)
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
	room->name = ft_strsub(*s, 0, (size_t)(tmp++ - *s));
	if (ft_expect(&tmp, "$nw $nw\n", &room->x, &room->y))
		return (1);
	ft_printf("New room:\n- Name = '%s'\n- X = %d\n- Y = %d\n",
		room->name, room->x, room->y);
	if ((item = ft_lstnew(room, sizeof(*room))) == NULL
		|| ft_lstadd(in, new))
		return (1);
	*s = tmp;
	return (0);
}

static int	process_node(const char **s, t_list **in)
{

}
