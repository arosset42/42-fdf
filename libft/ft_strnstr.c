/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosset <arosset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 14:40:00 by arosset           #+#    #+#             */
/*   Updated: 2016/11/14 14:24:14 by arosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t bg;
	size_t lt;

	lt = 0;
	bg = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (big[bg] != '\0' && bg <= len)
	{
		if (big[bg] == little[0])
		{
			while (little[lt] == big[bg + lt] && (bg + lt) < len)
			{
				if (lt == ft_strlen(little) - 1)
					return ((char *)&big[bg]);
				else
					lt++;
			}
		}
		bg++;
	}
	return (0);
}
