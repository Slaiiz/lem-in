/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 18:32:04 by vchesnea          #+#    #+#             */
/*   Updated: 2016/05/30 17:05:35 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include "libft.h"
# include "get_next_line.h"

typedef struct		s_room
{
	unsigned int	x;
	unsigned int	y;
}					t_room;

typedef struct		s_anthill
{
	s_room			*rooms[];
	s_node			*nodes[];
}					t_anthill;

typedef enum		e_error
{
	ERROR_OK,
	ERROR_MALFORMED_ROOM,
	ERROR_MALFORMED_NODE,
	ERROR_MALFORMED_COMMAND,
	ERROR_MALFORMED_COMMENT,
}					t_error;

typedef enum		e_command
{
	COMMAND_NONE,
	COMMAND_END,
	COMMAND_START,
	COMMAND_FIREPIT,
	COMMAND_WORMHOLE,
	COMMAND_DEATHSQUAD
}					t_command;

e_error				read_game_data(const char *s, t_anthill **out);

#endif
