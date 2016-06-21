/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_node.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/21 16:55:20 by vchesnea          #+#    #+#             */
/*   Updated: 2016/06/21 16:55:24 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int	process_node(const char **s, t_anthill *in)
{
	const char		*tmp;
	t_list			*new;
	t_room			*node_a;
	t_room			*node_b;

	tmp = *s - 1;
	while (*++tmp != '-')
		if (*tmp == '\0' || *tmp == '\n')
			return (1);
	node_a = in->rooms[key_to_hash(*s, (size_t)(tmp - *s)) % (10 * in->len)];
	*s = tmp + 1;
	while (*++tmp != '\n')
		if (*tmp == '\0')
			return (1);
	node_b = in->rooms[key_to_hash(*s, (size_t)(tmp - *s)) % (10 * in->len)];
	if (node_a == NULL || node_b == NULL ||
		(new = ft_lstnew(node_b, sizeof(node_b))) == NULL)
		return (1);
	ft_lstadd(&node_a->nodes, new);
	if ((new = ft_lstnew(node_a, sizeof(node_a))) == NULL)
		return (1);
	ft_lstadd(&node_b->nodes, new);
	ft_printf("Created linkage %s - %s\n", node_a->name, node_b->name);
	*s = ++tmp;
	return (0);
}
