/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoquel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 11:07:37 by achoquel          #+#    #+#             */
/*   Updated: 2019/02/11 16:33:14 by achoquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

int		julia_param(int x, int y, t_env *env)
{
	if (env->locked != 1)
	{
		if (x > 0 && x < 1000)
			env->jx = -(double)x / 1000;
		else if (x > 999 && x < 1280)
			env->jx = -(double)x / 1000;
		else if (x > 1279 && x < 2560)
			env->jx = (double)x / 1000;
		if (y > 0 && y < 770)
			env->jy = -(double)y / 1000;
		else if (y > 769 && y < 1000)
			env->jy = (double)y / 1000;
		else if (y > 999 && y < 1440)
			env->jy = (double)y / 1000;
		mlx_clear_window(env->mlx, env->win_main);
		draw_fractal(env);
	}
	return (0);
}

int		destroy_handler(t_env *env)
{
	mlx_clear_window(env->mlx, env->win_main);
	mlx_destroy_window(env->mlx, env->win_main);
	exit (0);
}

int		esc_handler(int key, t_env *env)
{
	if (key == 53)
		destroy_handler(env);
	return (0);
}

int		reset_handler(t_env *env)
{
	env->mfactor = 1;
	env->zfactor = 0;
	env->zoom = 650;
	env->mx = 0;
	env->my = 0;
	env->jx = 0;
	env->jy = 0;
	mlx_clear_window(env->mlx, env->win_main);
	draw_fractal(env);
	return (0);
}

int		move_handler(int key, t_env *env)
{
	if (key == 125)
		env->my -= (-1 * env->mfactor);
	else if (key == 126)
		env->my -= (1 * env->mfactor);
	else if (key == 124)
		env->mx -= (-1 * env->mfactor);
	else if (key == 123)
		env->mx -= (1 * env->mfactor);
	mlx_clear_window(env->mlx, env->win_main);
	draw_fractal(env);
	return (0);
}

int		fractal_changer(int key, t_env *env)
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

int		mouse_hooks(int key, int x, int y, t_env *env)
{
	(void)x;
	(void)y;
	if (key == 5 || key == 4 || (key == 1 && ft_strcmp(env->fract, "Julia") == 0))
	{
		if (key == 5)
			env->zoom *= (1.1 + env->zfactor);
		if (key == 4)
			env->zoom *= (1.1 + env->zfactor);
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

int		theme_handler(t_env *env)
{
	if (env->p == 15)
		env->p = 0;
	else
		++env->p;
	mlx_clear_window(env->mlx, env->win_main);
	draw_fractal(env);
	return (0);
}

int		key_hooks(int key, t_env *env)
{
	if (key == 125 || key == 126 || key == 124 || key == 123)
		return (move_handler(key, env));
	else if (key == 122 || key == 120 || key == 99 || key == 118 || key == 96 || key == 97)
		return (fractal_changer(key, env));
	else if (key == 115)
		env->zfactor += 0.1;
	else if (key == 119 && env->zfactor != 1)
		env->zfactor -= 0.1;
	else if (key == 116)
		++env->mfactor;
	else if (key == 121 && env->mfactor != 1)
		--env->mfactor;
	else if (key == 15)
		reset_handler(env);
	else if (key == 8)
		theme_handler(env);
	hud(env);
	return (0);
}
