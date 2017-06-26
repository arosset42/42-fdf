/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 18:11:22 by lfabbro           #+#    #+#             */
/*   Updated: 2015/11/30 11:59:21 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	int				i;
	unsigned char	*pt;

	i = 0;
	pt = b;
	while (len--)
	{
		pt[i] = ((unsigned char)c);
		i++;
	}
	return (b);
}
