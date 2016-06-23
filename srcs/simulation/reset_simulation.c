/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_simulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/21 16:55:53 by vchesnea          #+#    #+#             */
/*   Updated: 2016/06/21 16:55:54 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int	reposition_ants(t_hill *hill)
{
	unsigned int	i;
	t_ant			*ant;

	i = hill->n_ants;
	if ((hill->ants = malloc(sizeof(*hill->ants) * i)) == NULL)
		return (1);
	while (i-- > 0)
	{
		ant = &hill->ants[i];
		ant->room = hill->start;
		ant->state = STATE_HEALTHY;
	}
	return (0);
}

int			reset_simulation(t_hill *hill)
{
	if (reposition_ants(hill))
		return (1);
	return (0);
}
