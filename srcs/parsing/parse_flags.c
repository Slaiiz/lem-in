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

void	parse_flags(int argc, char **argv, unsigned short *in)
{
	char	*args;

	*in = 0x0000;
	while (argc > 1 && --argc)
	{
		if (*(++argv)[0] != '-')
			return ;
		args = *argv;
		while (*++args != '\0')
		{
			if (*args == 'f')
				*in |= F_FEATURES;
			else if (*args == 'd')
				*in |= F_DEBUGEN;
			else if (*args == 'a')
				*in |= F_OPT_AGGR;
			else if (*args == 't')
				*in |= F_OPT_TIME;
		}
	}
}
