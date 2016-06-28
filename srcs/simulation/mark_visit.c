/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mark_visit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 18:48:42 by vchesnea          #+#    #+#             */
/*   Updated: 2016/06/28 18:50:09 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int	mark_visit(t_list **out, t_room *in)
{
	t_list	*new;

	if ((new = ft_lstnew(in, sizeof(*in))) == NULL)
		return (1);
	ft_lstadd(out, new);
	in->visited = true;
	return (0);
}
