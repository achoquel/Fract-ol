/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoquel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 11:07:37 by achoquel          #+#    #+#             */
/*   Updated: 2019/02/13 17:35:57 by achoquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"
#include <stdio.h>

int		julia_param(int x, int y, t_env *env)
{
	if (env->locked != 1 && ft_strcmp(env->fract, "Julia") == 0)
	{
		if (x > 500)
		{
			env->jx = ((double)x - 1280) / 260;
			env->jy = ((double)y - 720) / 240;
		}
		mlx_clear_window(env->mlx, env->win_main);
		draw_fractal(env);
	}
	return (0);
}

int		destroy_handler(t_env *env)
{
	mlx_clear_window(env->mlx, env->win_main);
	mlx_destroy_window(env->mlx, env->win_main);
	exit(0);
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
	if (env->opti == 0)
		env->zoom = 650;
	else
		env->zoom = 200;
	env->mx = 0;
	env->my = 0;
	env->jx = 0;
	env->jy = 0;
	env->p = 0;
	mlx_clear_window(env->mlx, env->win_main);
	if (env->opti == 0)
		fract_init(env);
	else
		fract_initopti(env);
	draw_fractal(env);
	return (0);
}

int		key_hooks(int key, t_env *env)
{
	if (key == 125 || key == 126 || key == 124 || key == 123)
		return (move_handler(key, env));
	else if (key == 122 || key == 120 || key == 99 || key == 118 || key == 96
			|| key == 97 || key == 98)
		return (fractal_changer(key, env));
	else if (key == 115)
		env->zfactor += 0.1;
	else if (key == 119 && env->zfactor != 0.0)
		env->zfactor -= 0.1;
	else if (key == 116)
		++env->mfactor;
	else if (key == 121 && env->mfactor != 1)
		--env->mfactor;
	else if (key == 15)
		reset_handler(env);
	else if (key == 8)
		theme_handler(env);
	hud_master(env);
	return (0);
}
