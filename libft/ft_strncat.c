/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosset <arosset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 12:31:00 by arosset           #+#    #+#             */
/*   Updated: 2016/11/12 12:03:10 by arosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	is1;
	size_t	is2;

	is2 = 0;
	is1 = ft_strlen(s1);
	while (is2 < n && s2[is2] != '\0')
	{
		s1[is1] = s2[is2];
		is1++;
		is2++;
	}
	s1[is1] = '\0';
	return (s1);
}
