/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/05 15:10:58 by vchesnea          #+#    #+#             */
/*   Updated: 2016/07/05 15:10:59 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstdup(t_list *lst)
{
	t_list	*out;
	t_list	*new;

	out = NULL;
	if (lst == NULL)
		return (NULL);
	if (lst)
	{
		if (lst->next)
		{
			if ((out = ft_lstdup(lst->next)) == NULL)
				return (NULL);
		}
		if ((new = ft_lstnew(lst->content, lst->content_size)) == NULL)
			return (NULL);
		ft_lstadd(&out, new);
	}
	return (out);
}
