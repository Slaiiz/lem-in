/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preprocess.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/30 15:51:41 by vchesnea          #+#    #+#             */
/*   Updated: 2016/05/30 16:58:43 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int	process_command(const char **s, t_anthill *in, t_command command)
{
	if (ft_seekstr(s, "end"))
		command = COMMAND_END;
	else if (ft_seekstr(s, "start"))
		command = COMMAND_START;
	else if (ft_seekstr(s, "deathsquad"))
		command = COMMAND_DEATHSQUAD;
	else
		return (1);
	return (!ft_seekstr(s, "\n"));
}

static int	process_comment(const char **s, t_anthill *in, t_command command)
{
	while (**s != '\0' && **s != '\n')
		++*s;
	command = COMMAND_NONE;
	return (**s == '\0');
}

static int	process_room(const char **s, t_anthill *in, t_command command)
{
	command = COMMAND_NONE;
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
	e_command	command;

	if ((*out = malloc(sizeof(**out))) == NULL)
		return (1);
	ft_bzero(*out, sizeof(**out));
	if (!ft_expect(&s, "$n\n", &(*out)->n_ants))
		return (2);
	while (*s != '\0')
	{
		if (ft_expect(&s, "##") && process_command(&s, *out))
			return (ERR_MALFORMED_COMMAND);
		else if (ft_expect(&s, "#") && process_comment(&s, *out))
			return (ERR_MALFORMED_COMMENT);
		else if (process_room(&s, *out))
			return (ERR_MALFORMED_ROOM);
	}
}
