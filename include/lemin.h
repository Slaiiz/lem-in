/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 18:32:04 by vchesnea          #+#    #+#             */
/*   Updated: 2016/06/14 16:52:28 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
#define LEMIN_H

#include "libft.h"

#define F_FEATURES	0x0001
#define F_OPT_TIME	0x0002
#define F_OPT_AGGR	0x0004
#define F_DEBUGEN   0x0008

typedef enum		e_command
{
	COMMAND_NONE,
	COMMAND_END,
	COMMAND_START,
	COMMAND_FIREPIT,
	COMMAND_WORMHOLE,
	COMMAND_DEATHSQUAD
}					t_command;

typedef enum		e_state
{
	STATE_HEALTHY,
	STATE_DRUNK,
	STATE_ON_FIRE,
	STATE_DEAD
}					t_state;

typedef struct		s_room
{
	unsigned int	x;
	unsigned int	y;
	const char		*name;
	t_list			*nodes;
	unsigned int	visits;
	t_command		command;
}					t_room;

typedef struct		s_ant
{
	t_room			*room;
	t_state			state;
}					t_ant;

typedef struct		s_hill
{
	unsigned int	len;
	t_room			*end;
	t_ant			*ants;
	t_room			*start;
	unsigned int	n_ants;
	t_room			**rooms;
}					t_hill;

unsigned int		key_to_hash(const char *s, size_t len);

void				parse_flags(int argc, char **argv, unsigned short *in);
int					build_data(t_list *lst, t_hill *in);
int					parse_input(const char *s, t_hill *in);
int					read_input(const char **out);

int					process_command(const char **s, t_command *in);
int					process_comment(const char **s);
int					process_node(const char **s, t_hill *in);
int					process_room(const char **s, t_command cmd, t_list **in);

int					reset_simulation(t_hill *hill);
int					run_simulation(t_hill *hill, unsigned short flags);
int					compute_route(t_hill *hill, t_list ***out);

#endif
