/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_undefined.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 16:44:47 by arosset           #+#    #+#             */
/*   Updated: 2017/05/14 15:10:39 by arosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void	ft_undefined(t_args *cylva, char **fmt, int total)
{
	int		i;

	if ((S_OPE == 'c' || S_OPE == 's') && !S_PREC)
		S_PREC = -1;
	i = cylva->width - ((total < 0) ? 1 : total);
	if (S_MO_ZE == '0')
		ft_put_n_char('0', i);
	else if ((S_PL_SP == ' ' || (!S_PL_SP)) && !S_MO_ZE)
		ft_put_n_char(' ', i);
	if (cylva->width != 0 && total < 0)
		cylva->len_print += cylva->width + (total == -7 ? -1 : total);
	if (total == -7)
	{
		if (S_OPE)
		{
			write(1, &S_OPE, 1);
			cylva->len_print++;
			(*fmt)++;
		}
		if (S_MO_ZE == '-' && cylva->width > S_PREC)
			ft_put_n_char(' ', cylva->width - (total > 0 ? total : 1));
	}
}
