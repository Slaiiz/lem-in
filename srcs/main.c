/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/30 19:03:08 by vchesnea          #+#    #+#             */
/*   Updated: 2016/06/21 18:25:12 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int	create_anthill(t_anthill **out)
{
	const char	*input;
	t_anthill	*hill;

	if ((hill = malloc(sizeof(*hill))) == NULL)
		return (1);
	ft_bzero(hill, sizeof(*hill));
	if (read_input(&input) || parse_input(input, hill))
		return (1);
	*out = hill;
	return (0);
}

int			main(int argc, char **argv)
{
	t_anthill		*hill;
	unsigned short	flags;

	if (parse_flags(&argc, &argv, &flags)
		|| create_anthill(&hill)
		|| run_simulation(hill, flags))
	{
		ft_printf("#!fd=2^ERROR\n");
		return (1);
	}
	return (0);
}
