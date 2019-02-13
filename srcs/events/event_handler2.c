/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoquel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 16:50:12 by achoquel          #+#    #+#             */
/*   Updated: 2019/02/13 13:34:47 by achoquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

int	move_handler(int key, t_env *env)
{
	if (key == 125)
		env->y1 += (-1 * env->mfactor) / (env->zoom / 10);
	else if (key == 126)
		env->y1 += (1 * env->mfactor) / (env->zoom / 10);
	else if (key == 124)
		env->x1 += (-1 * env->mfactor) / (env->zoom / 10);
	else if (key == 123)
		env->x1 += (1 * env->mfactor) / (env->zoom / 10);
	mlx_clear_window(env->mlx, env->win_main);
	draw_fractal(env);
	return (0);
}

int	fractal_changer(int key, t_env *env)
{
	if (key == 122 && ft_strcmp(env->fract, "Mandelbrot") != 0)
		env->fract = "Mandelbrot";
	if (key == 120 && ft_strcmp(env->fract, "Julia") != 0)
		env->fract = "Julia";
	if (key == 99 && ft_strcmp(env->fract, "BurningShip") != 0)
		env->fract = "BurningShip";
	if (key == 118 && ft_strcmp(env->fract, "EvilEyes") != 0)
		env->fract = "EvilEyes";
	if (key == 96 && ft_strcmp(env->fract, "Lapin") != 0)
		env->fract = "Lapin";
	if (key == 97 && ft_strcmp(env->fract, "Dendrite") != 0)
		env->fract = "Dendrite";
	reset_handler(env);
	mlx_clear_window(env->mlx, env->win_main);
	draw_fractal(env);
	return (0);
}

int	mouse_hooks(int key, int x, int y, t_env *env)
{
	if (key == 5 || key == 4 || (key == 1 && ft_strcmp(env->fract, "Julia") ==
		0))
	{
		if (key == 4 || key == 5)
			zoom_handler(env, x, y, key);
		if (key == 1 && ft_strcmp(env->fract, "Julia") == 0)
		{
			if (env->locked == 0)
				env->locked = 1;
			else
				env->locked = 0;
			return (0);
		}
		mlx_clear_window(env->mlx, env->win_main);
		draw_fractal(env);
	}
	return (0);
}

int	theme_handler(t_env *env)
{
	if (env->p == 15)
		env->p = 0;
	else
		++env->p;
	mlx_clear_window(env->mlx, env->win_main);
	draw_fractal(env);
	return (0);
}
