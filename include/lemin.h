/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 18:32:04 by vchesnea          #+#    #+#             */
/*   Updated: 2016/06/01 13:33:17 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include "libft.h"

typedef enum		e_command
{
	COMMAND_NONE,
	COMMAND_END,
	COMMAND_START,
	COMMAND_FIREPIT,
	COMMAND_WORMHOLE,
	COMMAND_DEATHSQUAD
}					t_command;

typedef struct		s_room
{
	unsigned int	x;
	unsigned int	y;
	const char		*name;
	t_list			*nodes;
	t_command		command;
}					t_room;

typedef struct		s_anthill
{
	unsigned int	len;
	t_room			*end;
	t_room			*start;
	unsigned int	n_ants;
	t_room			**rooms;
}					t_anthill;

unsigned int		key_to_hash(const char *s, size_t len);
int					process_comment(const char **s);
int					process_node(const char **s, t_anthill *in);
int					process_command(const char **s, t_command *in);
int					process_room(const char **s, t_command command, t_list **in);

#endif
