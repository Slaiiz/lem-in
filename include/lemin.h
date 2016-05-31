/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 18:32:04 by vchesnea          #+#    #+#             */
/*   Updated: 2016/05/31 18:27:31 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include "libft.h"

typedef struct		s_item
{
	t_command		cmd;
	const char		*name;
}					t_item;

typedef struct		s_room
{
	unsigned int	x;
	unsigned int	y;
}					t_room;

typedef struct		s_node
{
	t_room			*exit_a;
	t_room			*exit_b;
}					t_node;

typedef struct		s_anthill
{
	t_room			*end;
	t_room			*start;
	unsigned int	n_ants;
	t_room			**rooms;
	t_node			**nodes;
}					t_anthill;

typedef enum		e_error
{
	ERROR_OK,
	ERROR_BAD_INPUT,
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

t_error				read_game_data(const char *s, t_anthill **out);
unsigned int		key_to_hash(const char *s);

#endif
