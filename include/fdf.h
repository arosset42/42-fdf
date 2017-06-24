/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/23 14:16:47 by arosset           #+#    #+#             */
/*   Updated: 2017/06/23 14:16:54 by arosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
#define FDF_H

#include "../libft/includes/libft.h"
#include <math.h>
#include <stdio.h>  	//perror
#include <string.h> 	//strerror
#include "../minilibx_macos/mlx.h"

typedef struct		s_fdf
{
	void 			*mlx;
	void 			*win;
	int				x;
	int				y;
}					t_fdf;

#endif
