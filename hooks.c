/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/31 23:29:56 by arosset           #+#    #+#             */
/*   Updated: 2017/08/01 18:09:20 by arosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		loop(t_env *e)
{
	pollevents();
	mlx_put_img_to_window();
}

struct s_key {
	int	active;
	int	press;
	int	func;
	void	(*press)(int key, struct s_env *);
	void	(*repeat)(int key, struct s_env *);
}			t_key;

void	add_key(int keycode, t_env *e, (press), (repeat))
{
	e->keys[keycode].press = press;
	e->keys[keycode].repeat = repeat;
	e->keys[keycode].active = 1;
}

struct s_env {
	

int		key_press(int keycode, t_env *e)
{
	e->keys[keycode].press = 1;
}



int		run()
{
	void	*mlx_ptr;

	mlx_hook(win, KEY_PRESS, MASK, key_press, e);
	mlx_loop_hook(mlx_ptr, loop, e);
	mlx_loop(mlx_ptr);
}
