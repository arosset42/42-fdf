/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosset <arosset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 12:52:26 by arosset           #+#    #+#             */
/*   Updated: 2016/11/14 12:37:47 by arosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	size_t bg;
	size_t lt;

	lt = 0;
	bg = 0;
	if (!little[lt])
		return ((char *)big);
	if (!big[bg])
		return (NULL);
	while (big[bg] != '\0')
	{
		if (big[bg] == little[0])
		{
			while (little[lt] == big[bg + lt])
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
