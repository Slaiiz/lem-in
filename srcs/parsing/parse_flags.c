/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/21 16:54:13 by vchesnea          #+#    #+#             */
/*   Updated: 2016/06/21 16:54:14 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int	parse_flags(int *argc, char ***argv, unsigned short *in)
{
	char	*args;

	while (*argc > 1)
	{
		if (*(++*argv)[0] == '-')
		{
			args = **argv;
			while (*++args != '\0')
			{
				if (*args == 'f')
					*in |= F_FEATURES;
			}
			--argc;
		}
	}
	return (0);
}
