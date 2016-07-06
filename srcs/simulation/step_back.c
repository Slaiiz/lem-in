/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 18:46:23 by vchesnea          #+#    #+#             */
/*   Updated: 2016/06/28 18:53:01 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int	step_back(t_list **route, t_room **out)
{
	ft_lstdelone(route, NULL);
	*out = (*route)->content;
	return (*route == NULL);
}
