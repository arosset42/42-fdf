/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosset <arosset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 15:42:25 by arosset           #+#    #+#             */
/*   Updated: 2016/11/16 11:40:54 by arosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

static int	ft_len(int *n, int *min)
{
	int		i;
	int		len;

	len = 1;
	i = 1;
	if (*n < 0)
	{
		*min = *min + 1;
		*n *= -1;
		len++;
	}
	while ((*n / i) >= 10)
	{
		i *= 10;
		len++;
	}
	return (len);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		min;

	min = 0;
	if (n == -2147483648)
	{
		str = ft_strnew(12);
		ft_strcpy(str, "-2147483648");
		str[11] = '\0';
		return (str);
	}
	len = ft_len(&n, &min);
	str = ft_strnew(len);
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	if (min == 1)
		str[0] = '-';
	while (len-- > min)
	{
		str[len] = n % 10 + '0';
		n /= 10;
	}
	return (str);
}
