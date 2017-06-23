/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosset <arosset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 11:21:25 by arosset           #+#    #+#             */
/*   Updated: 2016/11/14 13:10:27 by arosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*t_s1;
	unsigned char	*t_s2;

	t_s2 = (unsigned char *)s2;
	t_s1 = (unsigned char *)s1;
	i = 0;
	if (n == 0)
		return (0);
	while (t_s1[i] == t_s2[i] && i < n - 1)
		i++;
	return ((unsigned char)t_s1[i] - (unsigned char)t_s2[i]);
}
