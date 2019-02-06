/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoquel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 11:07:37 by achoquel          #+#    #+#             */
/*   Updated: 2019/02/06 15:11:51 by achoquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

void	esc_handler(t_env *env)
{
	int	i;

	i = 0;
	mlx_destroy_window(env->mlx, env->win_main);
	exit(0);
}

int		mouse_hooks(int key, int x, int y, t_env *env)
{
	x = y;
	if (key == 5)
		++env->zoom;
	if (key == 4)
		--env->zoom;
	mlx_clear_window(env->mlx, env->win_main);
	draw_fractal(env);
	return (0);
}

int		key_hooks(int key, t_env *env)
{
	if (key == 53)
		esc_handler(env);
	else if (key == 69)
		env->zoom += 1000;
	else if (key == 78)
		env->zoom -= 1000;
	else if (key == 1)
		env->my += -1;
	else if (key == 13)
		env->my += 1;
	else if (key == 2)
		env->mx += -1;
	else if (key == 0)
		env->mx += 1;
	else if (key == 15)
	{
		if (env->r == 0)
			env->r = 255;
		else
			env->r -= 5;
	}
	if (key == 5)
	{
		if (env->g == 0)
			env->g = 255;
		else
			env->g -= 5;
	}
	if (key == 11)
	{
		if (env->b == 0)
			env->b = 255;
		else
			env->b -= 5;
	}
	if (key == 122 && ft_strcmp(env->fract, "Mandelbrot") != 0)
		env->fract = "Mandelbrot";
	if (key == 120 && ft_strcmp(env->fract, "Julia") != 0)
		env->fract = "Julia";
	if (key == 99 && ft_strcmp(env->fract, "BurningShip") != 0)
		env->fract = "BurningShip";
	mlx_clear_window(env->mlx, env->win_main);
	draw_fractal(env);
	return (0);
}
