/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 18:18:59 by vchesnea          #+#    #+#             */
/*   Updated: 2016/06/03 17:58:33 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"

static int	read_number(const char **s, const char **format, va_list argp)
{
	size_t			n;
	void			*dst;
	const char		*tmp;

	tmp = *s;
	while (ft_isdigit(*tmp))
		++tmp;
	if ((tmp - *s) == 0)
		return (1);
	n = ft_atoi(*s);
	dst = va_arg(argp, size_t*);
	if (**format == 'b')
		*(unsigned char*)dst = n;
	else if (**format == 'h')
		*(unsigned short*)dst = n;
	else if (**format == 'w')
		*(unsigned int*)dst = n;
	else if (**format == 'g')
		*(unsigned long*)dst = n;
	*s = tmp;
	++*format;
	return (0);
}

static int	read_identifier(const char **s, va_list argp)
{
	const char	*tmp;
	const char	**dst;

	tmp = *s;
	if (!ft_isalpha(*tmp++))
		return (1);
	while (ft_isalnum(*tmp))
		++tmp;
	dst = va_arg(argp, const char**);
	if ((*(char**)dst = ft_strsub(*s, 0, (size_t)(tmp - *s))) == NULL)
		return (1);
	*s = tmp;
	return (0);
}

int			ft_expect(const char **s, const char *format, ...)
{
	char		c;
	const char	*tmp;
	va_list		argp;

	tmp = *s;
	va_start(argp, format);
	while ((c = *format++) != '\0')
	{
		if (c == '$' && (c = *format++))
		{
			if (c == 'n' && read_number(&tmp, &format, argp))
				return (1);
			else if (c == 'i' && read_identifier(&tmp, argp))
				return (1);
			else if (c == '$' && *tmp != c)
				return (1);
		}
		else if (*tmp++ != c)
			return (1);
	}
	*s = tmp;
	return (0);
}
