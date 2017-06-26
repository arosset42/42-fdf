/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <lfabbro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 17:19:33 by lfabbro           #+#    #+#             */
/*   Updated: 2016/03/04 11:19:28 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int			main(int argc, char **argv)
{
	int		err;

	err = 0;
	if (argc == 2)
	{
		if ((err = parse_map(argv[1])) < 0)
			return (ft_map_error(err));
	}
	else
		return (ft_argv_error());
	return (0);
}
