/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 18:04:26 by vchesnea          #+#    #+#             */
/*   Updated: 2016/06/01 18:16:14 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	char	*out;

	if ((out = malloc(sizeof(*s) * (len + 1))) == NULL)
		return (NULL);
	s = s + start;
	ft_memcpy(out, s, len);
	out[start + len] = '\0';
	return (out);
}
