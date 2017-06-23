/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosset <arosset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 11:21:07 by arosset           #+#    #+#             */
/*   Updated: 2016/12/12 10:55:26 by arosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*t_src;
	size_t			i;

	i = 0;
	t_src = (unsigned char *)s;
	while (i < n)
	{
		if (t_src[i] == (unsigned char)c)
			return ((unsigned char *)&t_src[i]);
		i++;
	}
	return (NULL);
}
