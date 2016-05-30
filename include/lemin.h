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

typedef enum
{
	ERROR_MALFORMED_COMMAND,
	ERROR_MALFORMED_COMMENT,
	ERROR_MALFORMED_ROOM,
	ERROR_MALFORMED_NODE
}	e_error;

# define PROPERTY_IS_VALID   1
# define PROPERTY_DEATHSQUAD 2

typedef enum
{
	COMMAND_NONE,
	COMMAND_END,
	COMMAND_START,
	COMMAND_FIREPIT,
	COMMAND_WORMHOLE,
	COMMAND_DEATHSQUAD
}	e_command;

#endif
