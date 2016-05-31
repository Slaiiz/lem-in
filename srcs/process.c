/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 18:30:07 by vchesnea          #+#    #+#             */
/*   Updated: 2016/05/31 18:30:08 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int	process_command(const char **s, t_command *in)
{
	if (ft_seekstr(s, "end"))
		*cmd = COMMAND_END;
	else if (ft_seekstr(s, "start"))
		*cmd = COMMAND_START;
	else if (ft_seekstr(s, "firepit"))
		*cmd = COMMAND_FIREPIT;
	else if (ft_seekstr(s, "wormwhole"))
		*cmd = COMMAND_WORMHOLE;
	else if (ft_seekstr(s, "deathsquad"))
		*cmd = COMMAND_DEATHSQUAD;
	else
		return (1);
	return (!ft_seekstr(s, "\n"));
}

static int	process_comment(const char **s)
{
	while (**s != '\0' && **s != '\n')
		++*s;
	return (**s == '\0');
}

static int	process_room(const char **s, t_command command, t_list **in)
{
	const char	*tmp;
	t_room		room;
	t_item		*item;
	t_list		*list;

	if ((item = malloc(sizeof(*item))) == NULL)
		return (1);
	tmp = *s - 1;
	while (*++tmp != ' ')
		if (*tmp == '\0' || *tmp == '\n')
			return (1);
	item->name = ft_strsub(*s, 0, (size_t)tmp);
	item->cmd = command;
	if ((list = ft_lstnew(item, sizeof(*item)) == NULL)
		return (1);
	ft_lstadd(in, list);
	*s = tmp;
	*in = list;
	return (0);
}

/*
** read_game_data:
** Step 1: Ant count check
** Step 2: Room definition check
** - Command
** - Comment
** - Room definition
** Step 3: Node definition check
** - Comment
** - Node definition
*/

t_error		read_game_data(const char *s, t_anthill **out)
{
	t_list			*items;
	t_command		command;

	if ((*out = malloc(sizeof(**out))) == NULL)
		return (1);
	ft_bzero(*out, sizeof(**out));
	if (!ft_expect(&s, "$n\n", &(*out)->n_ants))
		return (2);
	items = NULL;
	while (*s != '\0')
	{
		if (ft_expect(&s, "##"))
		{
			if (process_command(&s, &command))
				return (ERROR_MALFORMED_COMMAND);
			if (process_room(&s, &command, &items))
				return (ERROR_MALFORMED_ROOM);
			command = COMMAND_NONE;
		}
		else if (ft_expect(&s, "#") && process_comment(&s))
			return (ERROR_MALFORMED_COMMENT);
		else if (process_room(&s, command))
			return (ERROR_MALFORMED_ROOM);
	}
	return (ERROR_OK);
}
