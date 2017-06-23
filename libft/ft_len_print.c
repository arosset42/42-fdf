/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 15:10:59 by arosset           #+#    #+#             */
/*   Updated: 2017/05/12 15:11:01 by arosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

int		ft_len_print_str(t_args *cylva)
{
	int	max;

	max = 0;
	if (S_OPE == 's' && !S_M_LEN)
		max = ft_strlen(cylva->str);
	else if (S_OPE == 'S' || (S_M_LEN == 'l' && S_OPE == 's'))
		max = ft_wstrlen(cylva->wstr, cylva->precision);
	else if (S_OPE == 'c' && !S_M_LEN)
		max = 1;
	else
	{
		if (cylva->wchar <= 0x7F)
			max = 1;
		else if (cylva->wchar <= 0x7FF)
			max = 2;
		else if (cylva->wchar <= 0xFFFF)
			max = 3;
		else
			max = 4;
	}
	if (cylva->precision >= 0 && S_OPE != 'c' && S_OPE != 'C')
		return (max > cylva->precision ? cylva->precision : max);
	else
		return (max);
}

int		ft_wstrlen(wchar_t *ws, int max)
{
	int	i;
	int	len;

	if (!ws)
		return (-1);
	i = 0;
	len = 0;
	if (max == -1)
		max = 2147483647;
	while (ws[i])
	{
		if (len + 1 <= max && ws[i] <= 0x7F)
			len += 1;
		else if (len + 2 <= max && ws[i] <= 0x7FF)
			len += 2;
		else if (len + 3 <= max && ws[i] <= 0xFFFF)
			len += 3;
		else if (len + 4 <= max)
			len += 4;
		i++;
	}
	return (len);
}
