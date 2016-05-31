/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/30 19:03:08 by vchesnea          #+#    #+#             */
/*   Updated: 2016/05/31 16:29:43 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int	read_input(const char **out)
{
	size_t		len;
	size_t		size;
	const char	*old;
	const char	*new;

	if ((new = malloc(16 * sizeof(*new))) == NULL)
		return (1);
	old = new;
	size = 0;
	while ((len = read(0, (char*)new + size, 16 - (size % 16))))
	{
		size += len;
		if (!(size % 16))
		{
			if ((new = malloc((16 + size) * sizeof(*new))) == NULL)
				return (1);
			ft_memcpy((char*)new, (char*)old, size);
			free((char*)old);
		}
		old = new;
	}
	((char*)new)[size] = '\0';
	*out = new;
	return (0);
}

int			main(int argc, char **argv)
{
	const char	*input;
	t_anthill	*gamedata;

	if (read_input(&input) || read_game_data(input, &gamedata) != ERROR_OK)
	{
		ft_printf("#!fd=2^ERROR\n");
		return (ERROR_BAD_INPUT);
	}
	return (0);
}
