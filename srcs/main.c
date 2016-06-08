/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/30 19:03:08 by vchesnea          #+#    #+#             */
/*   Updated: 2016/06/07 16:25:03 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int	build_room_data(t_list *lst, t_anthill *in)
{
	size_t			len;
	unsigned int	hash;
	t_room			*room;

	if ((len = ft_lstlen(lst)) < 1)
		return (1);
	if ((in->rooms = ft_memalloc(10 * len * sizeof(*in->rooms))) == NULL)
		return (1);
	while (lst)
	{
		room = (t_room*)lst->content;
		hash = key_to_hash(room->name, ft_strlen(room->name)) % (10 * len);
		ft_printf("Room '%s' has hash: {{red;u}}%#x{{eoc;}}\n",
			room->name, hash);
		if (room->command == COMMAND_START)
			in->start = room;
		else if (room->command == COMMAND_END)
			in->end = room;
		in->rooms[hash] = room;
		lst = lst->next;
	}
	in->len = len;
	return (0);
}

/*
** parse_input:
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
		if ((!ft_expect(&s, "##") && (process_command(&s, &command)
			|| process_room(&s, command, &items)))
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

	if (read_input(&input) || parse_input(input, &data))
	{
		ft_printf("#!fd=2^ERROR\n");
		return (1);
	}
	return (0);
}
