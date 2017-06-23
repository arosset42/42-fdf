/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 15:10:31 by arosset           #+#    #+#             */
/*   Updated: 2017/05/14 14:48:47 by arosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void	ft_get_tag(char **format, t_args *cylva)
{
	(*format)++;
	ft_get_flags(format, cylva);
	if (ft_isdigit(**format))
	{
		cylva->width = ft_atoi(*format);
		*format += nblen(cylva->width, 10);
	}
	ft_get_precision(format, cylva);
	ft_get_length(format, cylva);
	ft_error_double_f(format, cylva);
	cylva->operation = **format;
	ft_error_tag(cylva);
}

void	ft_get_length(char **fmt, t_args *cylva)
{
	while (**fmt && ft_str_index("hjzl", **fmt) != -1)
	{
		if (**fmt == *(*fmt + 1) || *(*fmt + 1) == 'h')
		{
			if (**fmt == 'h' || **fmt == 'l')
				cylva->m_lenght = **fmt - 32;
			else
				cylva->m_lenght = 'L';
			(*fmt)++;
		}
		else
			cylva->m_lenght = **fmt;
		(*fmt)++;
	}
}

void	ft_get_precision(char **format, t_args *cylva)
{
	if (**format == '.')
	{
		while (**format == '.')
			(*format)++;
		if (ft_isdigit(*(*(format))))
		{
			cylva->precision = ft_atoi(*(format));
			*format += nblen(cylva->precision, 10);
		}
	}
	else
		cylva->precision = -1;
}

void	ft_get_flags(char **format, t_args *cylva)
{
	while (**format && ft_str_index("#+- 0", **format) != -1)
	{
		if (**format == '#' && cylva->f_diese == 0)
			cylva->f_diese = '#';
		if (**format == '0' && cylva->f_mo_ze != '-')
			cylva->f_mo_ze = **format;
		if (**format == '-')
			cylva->f_mo_ze = **format;
		if (**format == ' ' && cylva->f_pl_sp == 0)
			cylva->f_pl_sp = **format;
		if (**format == '+')
			cylva->f_pl_sp = **format;
		(*format)++;
	}
}
