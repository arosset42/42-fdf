/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 14:44:06 by arosset           #+#    #+#             */
/*   Updated: 2017/07/29 18:11:35 by arosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_usage(void)
{
	ft_putendl_fd("\n\033[32musage :\033[00m ./fdf source_file.fdf", 2);
}

void 	ft_error_arg(int i)
{
	i -= 1;
	if (i == 0)
		ft_putendl_fd("No argument.", 2);
	else
		ft_putendl_fd("Too many argument.", 2);
	ft_usage();
}

void	ft_error(int c, char *s)
{
	ft_putstr_fd("\033[31mError : \033[00m", 2);
	if (c == 1)
		ft_error_arg(ft_atoi(s));
	if (c == 2)
	{
		ft_putstr_fd("./fdf ", 2);
		ft_putstr_fd(s, 2);
		ft_putendl_fd(" : invalid file.", 2);
		ft_usage();
	}
	if (c == 3)
	{
		ft_putstr_fd("./fdf ", 2);
		ft_putstr_fd(s, 2);
		ft_putendl_fd(" : invalid map.", 2);
		ft_usage();
	}
	if (c == 4)
		ft_putendl_fd("Malloc", 2);
	exit(EXIT_FAILURE);
}
