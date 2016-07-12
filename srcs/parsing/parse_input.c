/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/21 16:54:21 by vchesnea          #+#    #+#             */
/*   Updated: 2016/06/21 16:54:26 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int static	parse_room_definitions(const char **s, t_hill *in)
{
	const char	*tmp;
	t_list		*items;
	t_command	command;

	tmp = *s;
	while (*tmp != '\0')
	{
		if (!ft_expect(&tmp, "##"))
		{
			if (process_command(&tmp, &command))
				return (1);
			process_room(&tmp, command, &items);
		}
		else if (!ft_expect(&tmp, "#"))
		{
			if (process_comment(&tmp))
				return (1);
		}
		else if (process_room(&tmp, COMMAND_NONE, &items))
			break ;
	}
	if (build_data(items, in))
		return (1);
	*s = tmp;
	return (0);
}

int static	parse_node_definitions(const char **s, t_hill *in)
{
	const char	*tmp;

	tmp = *s;
	while (*tmp != '\0')
	{
		if (!ft_expect(&tmp, "#"))
		{
			if (process_comment(&tmp))
				return (1);
		}
		else if (process_node(&tmp, in))
			return (1);
	}
	*s = tmp;
	return (0);
}

int			parse_input(const char *s, t_hill *in)
{
	if (ft_expect(&s, "$nw\n", &in->n_ants))
		return (1);
	if (parse_room_definitions(&s, in))
		return (1);
	if (parse_node_definitions(&s, in))
		return (1);
	return (0);
}
