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

static int	reposition_ants(t_anthill *hill)
{
	unsigned int	i;
	t_ant			*ant;

	i = anthill->n_ants;
	if ((anthill->ants = malloc(sizeof(*anthill->ants) * i)) == NULL)
		return (1);
	while (i-- > 0)
	{
		ant = &anthill->ants[i];
		ant->room = anthill->start;
		ant->state = STATE_HEALTHY;
	}
	return (0);
}

int			reset_simulation(t_anthill *hill)
{
	if (reposition_ants(hill))
		return (1);
	return (0);
}
