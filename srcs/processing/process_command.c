/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/21 16:54:51 by vchesnea          #+#    #+#             */
/*   Updated: 2016/06/21 16:55:02 by vchesnea         ###   ########.fr       */
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
