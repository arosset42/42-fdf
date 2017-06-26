/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_imaxtoa_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 18:34:51 by lfabbro           #+#    #+#             */
/*   Updated: 2016/03/21 12:54:19 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h> 
#include <inttypes.h>

static int		get_size(intmax_t value, int base)
{
	int			size;

	size = 0;
	if (value < 0)
	{
		value *= -1;
	}
	while (value)
	{
		value /= base;
		++size;
	}
	return (size);
}

static char		*return_zero(void)
{
	char		*num;

	if ((num = (char *)malloc(sizeof(char) * 2)) == NULL)
		return (NULL);
	num[0] = '0';
	num[1] = '\0';
	return (num);
}

static char		*imaxtoa_base_return(intmax_t value, int base, char set)
{
	int			size;
	char		*num;
	uintmax_t	uvalue;

	size = get_size(value, base);
	uvalue = value;
	if ((num = (char*)malloc(sizeof(char) * size)) == NULL)
		return (NULL);
	num[size] = '\0';
	if (value < 0)
	{
		uvalue = -value;
	}
	while (uvalue)
	{
		if (uvalue % base < 10)
			num[--size] = "0123456789"[uvalue % base];
		else
			num[--size] = set + ((uvalue % base) - 10);
		uvalue /= base;
	}
	return (num);
}

char			*ft_imaxtoa_base(intmax_t value, int base, char set)
{
	if (base < 2 || base > 16)
		return (NULL);
	if (value == 0)
		return (return_zero());
	return(imaxtoa_base_return(value, base, set));
}
