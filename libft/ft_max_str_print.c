/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max_str_print.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 15:30:44 by arosset           #+#    #+#             */
/*   Updated: 2017/05/09 15:31:02 by arosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

int		ft_str_max_print(t_args *cylva)
{
	int	max;

	max = 0;
	if (S_OPE == 's' && !S_M_LEN)
		max = ft_strlen(cylva->str);
	else if (S_OPE == 'S' || (S_M_LEN == 'l' && S_OPE == 's'))
		max = ft_wstrlen(cylva->wstr, S_PREC);
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
	if (S_PREC >= 0 && S_OPE != 'c' && S_OPE != 'C')
		return (max > S_PREC ? S_PREC : max);
	else
		return (max);
}

int		ft_nbr_max_print(long long int nbr, t_args *cylva)
{
	int		max;
	int		len;

	len = (nbr < 0) ? 1 : 0;
	ft_set_base(cylva);
	if (ft_str_index("dDi", S_OPE) != -1)
		len += nblen(nbr, cylva->base);
	else
		len = unblen((unsigned long long)nbr, cylva->base);
	max = (len > S_PREC) ? len : S_PREC;
	if (max == S_PREC && !cylva->width && (S_OPE == 'o' || S_OPE == 'O'))
		max--;
	if ((S_DIESE == '#' && (S_OPE == 'o' || S_OPE == 'O')) ||
			(S_PL_SP && S_OPE != '%'))
		max++;
	if ((S_DIESE == '#' && (S_OPE == 'x' || S_OPE == 'X')) || S_OPE == 'p')
		max += 2;
	if (!nbr && !S_PREC)
		max--;
	return (max);
}

void	ft_set_base(t_args *cylva)
{
	if (S_OPE == 'x' || S_OPE == 'X' || S_OPE == 'p')
		cylva->base = 16;
	else if (S_OPE == 'o' || S_OPE == 'O')
		cylva->base = 8;
	else
		cylva->base = 10;
	if (S_OPE == '%')
		S_PREC = -1;
}
