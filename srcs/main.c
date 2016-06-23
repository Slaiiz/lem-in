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

static int	create_hill(t_hill **out)
{
	t_hill		*hill;
	const char	*input;

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
	t_hill			*hill;
	unsigned short	flags;

	parse_flags(argc, argv, &flags);
	if (create_hill(&hill) || run_simulation(hill, flags))
	{
		ft_printf("#!fd=2^ERROR\n");
		return (1);
	}
	return (0);
}
