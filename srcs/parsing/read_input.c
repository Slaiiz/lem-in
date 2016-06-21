/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/21 16:54:32 by vchesnea          #+#    #+#             */
/*   Updated: 2016/06/21 16:54:39 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int	read_input(const char **out)
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
