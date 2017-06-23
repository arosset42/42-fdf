/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/14 14:42:42 by arosset           #+#    #+#             */
/*   Updated: 2017/05/14 14:42:52 by arosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void	ft_error_tag(t_args *cylva)
{
	if (ft_str_index("uU", cylva->operation) != -1 && S_PL_SP)
		S_PL_SP = 0;
	if (S_PL_SP && S_OPE == 'p')
		S_PL_SP = 0;
	if (S_PL_SP && (S_OPE == 'o' || S_OPE == 'x' ||
			S_OPE == 'O' || S_OPE == 'X'))
		S_PL_SP = 0;
}

void	ft_error_double_f(char **format, t_args *cylva)
{
	while (ft_str_index(".#0+ ", **format) != -1)
	{
		if (!cylva->f_diese || !cylva->f_mo_ze || !cylva->f_pl_sp)
			ft_get_flags(format, cylva);
		else if (**format == '+')
		{
			cylva->f_pl_sp = '+';
			(*format)++;
		}
		else
			(*format)++;
	}
	if (cylva->f_diese == '#' && cylva->f_mo_ze == '-' && cylva->f_pl_sp == '+')
		cylva->precision = 0;
}
