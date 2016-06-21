/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_simulation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/21 16:56:02 by vchesnea          #+#    #+#             */
/*   Updated: 2016/06/21 17:21:53 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int	run_simulation(t_anthill *anthill)
{
	if (reset_simulation(anthill))
		return (1);
	return (0);
}
