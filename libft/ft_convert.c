/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 15:10:20 by arosset           #+#    #+#             */
/*   Updated: 2017/05/14 14:57:35 by arosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void			ft_convert(va_list ap, t_args *cylva)
{
	long long int	ret;

	ret = 0;
	if (S_OPE == '%')
		ret = 1;
	else if (S_OPE == 'C' || (S_OPE == 'l' && S_OPE == 'c'))
		cylva->wchar = va_arg(ap, wchar_t);
	else if (S_OPE == 's' && S_M_LEN != 'l')
		cylva->str = va_arg(ap, char *);
	else if (S_OPE == 'S' || (S_M_LEN == 'l' && S_OPE == 's'))
		cylva->wstr = va_arg(ap, wchar_t *);
	else if (S_OPE == 'c')
		cylva->c = va_arg(ap, int);
	else
		ret = ft_convert_nb(ap, cylva);
	if (ret < 0 && ft_str_index("dDi", S_OPE) != -1
			&& ret != -9223372036854775807 - 1)
	{
		cylva->f_pl_sp = '-';
		ret *= -1;
	}
	if (ft_str_index("pdDioOuUxX%", S_OPE) != -1)
		ft_print_nbr(cylva, ret);
	else
		ft_print_str(cylva);
}

long long int	ft_convert_nb(va_list ap, t_args *cylva)
{
	long long int	ret;

	if (S_M_LEN || ft_str_index("DIOU", S_OPE) != -1)
	{
		if (ft_str_index("oOuUxX", S_OPE) != -1)
			ret = ft_convert_uint(ap, cylva);
		else
			ret = ft_convert_int(ap, cylva);
	}
	else
	{
		if (ft_str_index("di", S_OPE) != -1)
			ret = va_arg(ap, int);
		else if (ft_str_index("ouxX", S_OPE) != -1)
			ret = va_arg(ap, unsigned int);
		else
			ret = va_arg(ap, long long);
	}
	return (ret);
}

long long int	ft_convert_uint(va_list ap, t_args *cylva)
{
	long long int	ret;

	ret = 0;
	if (S_M_LEN == 'H')
	{
		ret = va_arg(ap, unsigned int);
		if (ret != 65535)
			ret = (unsigned char)ret;
	}
	else if (S_M_LEN == 'l' || ft_isupper(S_OPE))
		ret = va_arg(ap, unsigned long);
	else if (S_M_LEN == 'h')
		ret = (unsigned short)va_arg(ap, unsigned int);
	else if (S_M_LEN == 'L')
		ret = va_arg(ap, unsigned long long);
	else if (S_M_LEN == 'j')
		ret = va_arg(ap, uintmax_t);
	else
		ret = va_arg(ap, size_t);
	return (ret);
}

long long int	ft_convert_int(va_list ap, t_args *cylva)
{
	long long int	ret;

	if (S_M_LEN == 'H')
	{
		if (S_OPE == 'D')
			ret = va_arg(ap, unsigned long);
		else
		{
			ret = va_arg(ap, int);
			if (ret != 65535)
				ret = (signed char)ret;
		}
	}
	else if (S_M_LEN == 'l' || ft_isupper(S_OPE))
		ret = va_arg(ap, long);
	else if (S_M_LEN == 'h')
		ret = (short)va_arg(ap, int);
	else if (S_M_LEN == 'L')
		ret = va_arg(ap, long long);
	else if (S_M_LEN == 'j')
		ret = va_arg(ap, uintmax_t);
	else
		ret = va_arg(ap, size_t);
	return (ret);
}
