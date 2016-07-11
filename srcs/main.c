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

int	static	error(char const *s)
{
	ft_printf("#!fd=2^%s\n", s);
	return (1);
}

int static	create_hill(t_hill **out, unsigned short flags)
{
	t_hill		*hill;
	char const	*input;

	if ((hill = malloc(sizeof(*hill))) == NULL)
		exit(1);
	ft_bzero(hill, sizeof(*hill));
	hill->flags = flags;
	if (read_input(&input) || parse_input(input, hill)
		|| !hill->start || !hill->end)
		return (1);
	*out = hill;
	return (0);
}

int			main(int argc, char **argv)
{
	t_hill			*hill;
	unsigned short	flags;

	parse_flags(argc, argv, &flags);
	if (create_hill(&hill, flags))
		return (error("ERROR"));
	if (run_simulation(hill))
		return (error("ERROR"));
	return (0);
}
