/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 16:58:20 by vchesnea          #+#    #+#             */
/*   Updated: 2016/06/14 17:09:26 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLAGS_H
#define FLAGS_H

#include "libft.h"

typedef enum	e_type
{
	TYPE_CHECK,
	TYPE_NUMBER,
	TYPE_STRING
}				t_type;

typedef struct	s_flags
{
	
}				t_flags;

int				ft_register_flag(const char *alias, t_type type, t_flags *in);
int				ft_get_flag(const char *alias, size_t *value);

#endif
