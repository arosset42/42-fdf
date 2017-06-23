/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosset <arosset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 15:07:36 by arosset           #+#    #+#             */
/*   Updated: 2016/11/28 12:31:32 by arosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

static int		ft_count_words(char const *s, char c)
{
	int		i;
	int		nb;

	i = 0;
	nb = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i - 1] == c || i == 0))
			nb++;
		i++;
	}
	return (nb);
}

static int		ft_length(char const *s, char c)
{
	int		i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
}

static char		*ft_tab(char const *s, char c)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)malloc(sizeof(str) * ft_length(s, c) + 1);
	while (s[i] != c && s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		i;
	int		index;

	i = 0;
	index = 0;
	if (s == NULL)
		return (NULL);
	tab = (char **)malloc(sizeof(tab) * (ft_count_words(s, c) + 1));
	if (tab == NULL)
		return (NULL);
	while (s[i])
	{
		if (s[i] != c && (s[i - 1] == c || i == 0))
		{
			tab[index] = ft_tab(&s[i], c);
			index++;
		}
		i++;
	}
	tab[index] = NULL;
	return (tab);
}
