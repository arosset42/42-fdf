/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosset <arosset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 12:44:05 by arosset           #+#    #+#             */
/*   Updated: 2016/11/12 12:03:02 by arosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char		*d;
	const char	*s;
	size_t		count;
	size_t		dlen;

	d = dst;
	s = src;
	count = size;
	while (count-- != 0 && *d != '\0')
		d++;
	dlen = d - dst;
	count = size - dlen;
	if (count == 0)
		return (dlen + ft_strlen(s));
	while (*s != '\0')
	{
		if (count != 1)
		{
			*d++ = *s;
			count--;
		}
		s++;
	}
	*d = '\0';
	return (dlen + (s - src));
}
