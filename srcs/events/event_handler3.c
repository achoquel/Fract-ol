/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoquel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 13:29:46 by achoquel          #+#    #+#             */
/*   Updated: 2019/02/14 13:08:13 by achoquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

void	iter_init(t_env *env)
{
	if (ft_strcmp(env->fract, "Mandelbrot") == 0 ||
		ft_strcmp(env->fract, "Mandelbar") == 0 ||
			ft_strcmp(env->fract, "Lapin") == 0)
		env->iter = 50;
	else if (ft_strcmp(env->fract, "Julia") == 0 ||
			ft_strcmp(env->fract, "BurningShip") == 0 ||
			ft_strcmp(env->fract, "Juliabs") == 0)
		env->iter = 70;
	else if (ft_strcmp(env->fract, "EvilEyes") == 0 ||
			ft_strcmp(env->fract, "Dendrite") == 0)
		env->iter = 150;
}

void	fract_init(t_env *env)
{
	if (ft_strcmp(env->fract, "Mandelbrot") == 0 ||
		ft_strcmp(env->fract, "Mandelbar") == 0)
	{
		env->x1 = -2.8;
		env->y1 = -1.1;
	}
	else if (ft_strcmp(env->fract, "BurningShip") == 0)
	{
		env->x1 = -2.8;
		env->y1 = -1.5;
	}
	else if (ft_strcmp(env->fract, "EvilEyes") == 0)
	{
		env->x1 = -2.3;
		env->y1 = -1.03;
	}
	else if (ft_strcmp(env->fract, "Julia") == 0 ||
			ft_strcmp(env->fract, "Juliabs") == 0 ||
			ft_strcmp(env->fract, "Lapin") == 0 ||
			ft_strcmp(env->fract, "Dendrite") == 0)
	{
		env->x1 = -2.5;
		env->y1 = -1.03;
	}
	iter_init(env);
}

void	fract_initopti(t_env *env)
{
	if (ft_strcmp(env->fract, "Mandelbrot") == 0 ||
		ft_strcmp(env->fract, "Mandelbar") == 0)
	{
		env->x1 = -2.3;
		env->y1 = -1;
	}
	else if (ft_strcmp(env->fract, "BurningShip") == 0)
	{
		env->x1 = -2;
		env->y1 = -1.5;
	}
	else if (ft_strcmp(env->fract, "EvilEyes") == 0)
	{
		env->x1 = -1.5;
		env->y1 = -1.03;
	}
	else if (ft_strcmp(env->fract, "Julia") == 0 ||
			ft_strcmp(env->fract, "Juliabs") == 0 ||
			ft_strcmp(env->fract, "Lapin") == 0 ||
			ft_strcmp(env->fract, "Dendrite") == 0)
	{
		env->x1 = -1.5;
		env->y1 = -1.03;
	}
	iter_init(env);
}

void	zoom_handler(t_env *env, int x, int y, int key)
{
	if (key == 5)
	{
		env->x1 = (x / env->zoom + env->x1) - (x / (env->zoom /
					(1.1 + env->zfactor)));
		env->y1 = (y / env->zoom + env->y1) - (y / (env->zoom /
					(1.1 + env->zfactor)));
		env->zoom /= 1.1;
	}
	if (key == 4)
	{
		env->x1 = (x / env->zoom + env->x1) - (x / (env->zoom *
					(1.1 + env->zfactor)));
		env->y1 = (y / env->zoom + env->y1) - (y / (env->zoom *
					(1.1 + env->zfactor)));
		env->zoom *= (1.1 + env->zfactor);
	}
}

int		hud_master(t_env *env)
{
	if (env->opti == 0)
		return (hud(env));
	else
		return (0);
}
