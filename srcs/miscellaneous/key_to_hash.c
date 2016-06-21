/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_to_hash.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/21 16:53:38 by vchesnea          #+#    #+#             */
/*   Updated: 2016/06/21 16:53:51 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

unsigned int	key_to_hash(const char *s, size_t len)
{
	unsigned int	hash;

	hash = 0x726dc07b;
	while (len-- && *s != '\0')
		hash = (hash / 7) + (*s++ * 0x5940bd67 ^ hash);
	return (hash);
}
