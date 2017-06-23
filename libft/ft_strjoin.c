/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosset <arosset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 12:48:52 by arosset           #+#    #+#             */
/*   Updated: 2016/11/11 15:04:23 by arosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*frais;
	int		i;
	int		y;
	int		len;

	y = 0;
	if ((i = 0) && ft_strcmp(s1, "") == 0)
		return ((char *)s1);
	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (!(frais = ft_strnew(len)))
		return (NULL);
	while (s1[i])
	{
		frais[i] = s1[i];
		i++;
	}
	while (s2[y])
		frais[i++] = s2[y++];
	return (frais);
}
