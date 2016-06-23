/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 14:22:06 by vchesnea          #+#    #+#             */
/*   Updated: 2016/06/23 15:52:27 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_base(int n, int base)
{
	char	*str;

	str = ft_itoa_base(n, base);
	write(1, str, ft_strlen(str));
	free(str);
}
