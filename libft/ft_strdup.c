/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosset <arosset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 11:27:11 by arosset           #+#    #+#             */
/*   Updated: 2016/11/16 11:41:37 by arosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char	*ft_strdup(const char *s1)
{
	char *dest;

	dest = (char*)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (dest == NULL)
		return (0);
	ft_strcpy(dest, s1);
	return (dest);
}
