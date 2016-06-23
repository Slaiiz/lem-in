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

int	parse_input(const char *s, t_hill *in)
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
		else if (ft_expect(&s, "L") && process_room(&s, COMMAND_NONE, &items))
			break ;
	}
	if (build_data(items, in))
		return (1);
	while (*s != '\0')
		if ((!ft_expect(&s, "#") && process_comment(&s))
			|| (process_node(&s, in)))
			return (1);
	return (0);
}
