/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 16:59:02 by vchesnea          #+#    #+#             */
/*   Updated: 2016/06/14 17:09:36 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int	reset_simulation(t_anthill *anthill)
{
	unsigned int	i;
	t_ant			*ant;

	i = anthill->n_ants;
	if ((anthill->ants = malloc(sizeof(*(anthill->ants) * i))) == NULL)
		return (1);
	while (--i >= 0)
	{
		ant = &anthill->ants[i];
		ant->room = anthill->start;
		ant->state = STATE_HEALTHY;
	}
}

int			run_simulation(t_anthill *anthill)
{

}
