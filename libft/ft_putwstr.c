/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 18:19:49 by arosset           #+#    #+#             */
/*   Updated: 2017/05/10 18:19:54 by arosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void	ft_putwstr(wchar_t *ws, int len)
{
	int	i;

	i = 0;
	while (ws[i] && len >= 0)
	{
		if (ws[i] <= 0x7F)
			len -= 1;
		else if (ws[i] <= 0x7FF)
			len -= 2;
		else if (ws[i] <= 0xFFFF)
			len -= 3;
		else
			len -= 4;
		if (len >= 0)
			ft_putwchar(ws[i]);
		i++;
	}
}
