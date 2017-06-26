/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 16:23:14 by lfabbro           #+#    #+#             */
/*   Updated: 2015/11/30 12:03:43 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t		i;
	const char	*src_ptr;
	char		*dst_ptr;

	i = 0;
	src_ptr = (const char*)src;
	dst_ptr = (char*)dst;
	while (i < n)
	{
		dst_ptr[i] = src_ptr[i];
		if (dst_ptr[i] == (unsigned char)c)
			return (&dst_ptr[i + 1]);
		i++;
	}
	return (NULL);
}
