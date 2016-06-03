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

static int	build_room_data(t_list *in, t_anthill *in)
{
	size_t	len;
	t_list	*tmp;

	if ((len = ft_lstlen(in)) < 1)
		return (1);
	tmp = in;
	while (tmp)
}

/*
** process_input:
** Step 1: Ant count check
** Step 2: Room definition check
** - Command
** - Comment
** - Room definition
** Step 3: Node definition check
** - Comment
** - Node definition
*/

static int	parse_input(const char *s, t_anthill *in)
{
	t_list		*items;
	t_command	command;

	if (ft_expect(&s, "$nw\n", &in->n_ants))
		return (1);
	items = NULL;
	while (*s != '\0')
	{
		if ((!ft_expect(&s, "##") && process_command(&s, &command)
			&& process_room(&s, command, &items))
			|| (!ft_expect(&s, "#") && process_comment(&s)))
			return (1);
		else if (process_room(&s, COMMAND_NONE, &items))
			break ;
	}
	if (build_room_data(items, in))
		return (1);
	while (*s != '\0')
		if ((!ft_expect(&s, "#") && process_comment(&s))
			|| (process_node(&s, in)))
			return (1);
	return (0);
}

/*
** read_input:
** Read data from the standard input into a buffer.
*/

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

/*
** main:
*/

int			main(int argc, char **argv)
{
	t_anthill	data;
	const char	*input;

	if (read_input(&input) || process_input(input, &data))
	{
		ft_printf("#!fd=2^ERROR\n");
		return (ERROR_BAD_INPUT);
	}
	return (0);
}
