/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 18:30:07 by vchesnea          #+#    #+#             */
/*   Updated: 2016/06/01 13:25:19 by vchesnea         ###   ########.fr       */
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
	t_room		*room;

	tmp = *s - 1;
	while (*++tmp != ' ')
		if (*tmp == '\0' || *tmp == '\n')
			return (1);
	if ((size_t)(tmp - *s) < 1 || (room = malloc(sizeof(*room))) == NULL)
		return (1);
	room->name = ft_strsub(*s, 0, (size_t)(tmp++ - *s));
	if (!ft_expect(&tmp, "$n $n\n", &room->x, &room->y))
		return (1);
	ft_printf("New room:\n- Name = '%s'\n- X = %d\n- Y = %d\n",
	room->name, room->x, room->y);
	*s = tmp;
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

t_error 	read_game_data(const char *s, t_anthill **out)
{
    t_list      *items;
    t_command   command;

    if ((*out = malloc(sizeof(**out))) == NULL)
        return (ERROR_MALLOC);
    if (!ft_expect(&s, "$n\n", &(*out)->n_ants))
        return (ERROR_BAD_INPUT);
    items = NULL;
    while (*s != '\0')
    {
        if (ft_expect(&s, "##"))
        {
            if (process_command(&s, &command))
                return (ERROR_MALFORMED_COMMAND);
            if (process_room(&s, command, &items))
                return (ERROR_MALFORMED_ROOM);
        }
        else if (ft_expect(&s, "#") && process_comment(&s))
        	return (ERROR_MALFORMED_COMMENT);
        else if (process_room(&s, COMMAND_NONE, &items))
            return (ERROR_MALFORMED_ROOM);
    }
    return (ERROR_OK);
}
