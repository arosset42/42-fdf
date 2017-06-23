/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 15:11:20 by arosset           #+#    #+#             */
/*   Updated: 2017/05/14 15:04:20 by arosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void	ft_print_str(t_args *cylva)
{
	int	total;

	total = ft_str_max_print(cylva);
	if (S_OPE == 's' && S_PREC && !S_M_LEN && cylva->str == NULL)
		total = 6;
	ft_undefined(cylva, NULL, total);
	if (S_OPE == 's' && !S_M_LEN)
		total == 0 ? ft_put_len_str(NULL, -1) : ft_put_len_str(S_STR, total);
	else if (S_OPE == 'c' && !S_M_LEN)
		ft_putchar(cylva->c);
	else if (S_OPE == 'S' || (S_M_LEN == 'l' && S_OPE == 's'))
	{
		if (total == -1)
		{
			ft_put_len_str("(null)", 6);
			total = 6;
		}
		else
			ft_putwstr(cylva->wstr, total);
	}
	else
		ft_putwchar(cylva->wchar);
	cylva->len_print += total > cylva->width ? total : cylva->width;
	if (S_MO_ZE == '-')
		ft_put_n_char(' ', cylva->width - total);
}

void	ft_print_nbr(t_args *cylva, long long int nbr)
{
	int	max;

	if (!nbr && S_OPE != 'o' && S_OPE != 'O')
		S_DIESE = 0;
	if (!nbr && S_PREC == -1 && S_OPE == 'o' && S_DIESE == '#')
		S_PREC = 0;
	max = ft_nbr_max_print(nbr, cylva);
	cylva->len_print += BIGGER(max, BIGGER(cylva->width, S_PREC));
	ft_print_arg_nbr(cylva, max, nbr);
	if (cylva->base == 16 && S_OPE == 'X')
		cylva->base = 1;
	if (S_OPE == '%')
		write(1, "%", 1);
	if ((nbr || S_PREC) && S_OPE != '%')
		ft_print_base(cylva, nbr);
	if (S_MO_ZE == '-' && cylva->width > S_PREC)
		ft_put_n_char(' ', cylva->width - max);
}

void	ft_print_arg_nbr(t_args *cylva, int max, long long int nbr)
{
	if ((!S_MO_ZE || (S_MO_ZE == '0' && S_PREC >= 0)))
		ft_put_n_char(' ', cylva->width - max);
	if (S_PL_SP && S_OPE != '%')
		write(1, &S_PL_SP, 1);
	if ((S_DIESE == '#'
				&& (S_OPE == 'X' || S_OPE == 'x')) || S_OPE == 'p')
		S_OPE == 'X' ? write(1, "0X", 2) : write(1, "0x", 2);
	if (S_DIESE == '#' && (S_OPE == 'o' || S_OPE == 'O'))
	{
		write(1, "0", 1);
		S_PREC -= S_PREC > 0 ? 1 : 0;
	}
	if (S_MO_ZE == '0' && S_PREC == -1)
		ft_put_n_char('0', cylva->width - max);
	if (S_PREC > 0)
		ft_put_n_char('0', S_PREC - nblen(nbr, cylva->base));
}

void	ft_print_base(t_args *cylva, long long int nbr)
{
	char	*out;

	if (cylva->base == 1)
		cylva->base = -16;
	if (ft_str_index("dDi", S_OPE) != -1)
		out = (nbr == -9223372036854775807 - 1) ?
			ft_strdup("-9223372036854775808") : ft_itoa_base(nbr, cylva->base);
	else
		out = ft_uitoa_base((unsigned long long int)nbr, cylva->base);
	ft_put_len_str(out, ft_strlen(out));
	ft_memdel((void *)&out);
}
