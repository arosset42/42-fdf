/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosset <arosset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 13:04:22 by arosset           #+#    #+#             */
/*   Updated: 2016/11/14 12:42:32 by arosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char	*ft_strtrim(char const *s)
{
	char		*str;
	size_t		start;
	size_t		len;
	size_t		is;

	len = 0;
	is = 0;
	start = 0;
	if (s == NULL)
		return (0);
	while (s[is] == '\n' || s[is] == ' ' || s[is] == '\t')
		is++;
	if (is >= ft_strlen(s))
		return (ft_strnew(1));
	start = is;
	is = ft_strlen(s);
	while (s[is] == '\n' || s[is] == ' ' || s[is] == '\t' || s[is] == '\0')
		is--;
	len = (is - start + 1);
	str = ft_strsub(s, start, len);
	if (str == NULL)
		return (0);
	return (str);
}
