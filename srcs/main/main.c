/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoquel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 11:05:37 by achoquel          #+#    #+#             */
/*   Updated: 2019/02/11 16:26:21 by achoquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

int		hud(t_env *env)
{
	char	*t1;
	char	*t2;

	t1 = ft_itoa(env->mfactor);
	t2 = ft_itoa(env->zfactor * 10);
	if ((env->img = mlx_xpm_file_to_image(env->mlx, "./img/ath.xpm", &env->size_l, &env->bpp)) == NULL)
		return (error(3));
	mlx_put_image_to_window(env->mlx, env->win_main, env->img, 0, 0);
	mlx_destroy_image(env->mlx, env->img);
	mlx_string_put(env->mlx, env->win_main, 210, 1222, 0xFFFFFF, env->fract);
	mlx_string_put(env->mlx, env->win_main, 210, 1255, 0xFFFFFF, t1);
	mlx_string_put(env->mlx, env->win_main, 210, 1288, 0xFFFFFF, t2);
	mlx_string_put(env->mlx, env->win_main, 210, 1320, 0xFFFFFF, get_palette(env));
	free(t1);
	free(t2);
	return (0);
}


int		draw_fractal(t_env *env)
{
	if (ft_strcmp(env->fract, "Mandelbrot") == 0)
		return (mandelbrot(env));
	else if (ft_strcmp(env->fract, "Julia") == 0)
		return (julia(env));
	else if (ft_strcmp(env->fract, "BurningShip") == 0)
		return (burning(env));
	else if (ft_strcmp(env->fract, "EvilEyes") == 0)
		return (eye(env));
	else if (ft_strcmp(env->fract, "Lapin") == 0)
		return (douady(env));
	else if (ft_strcmp(env->fract, "Dendrite") == 0)
		return (dendrite(env));
	return (0);
}

int		env_init(t_env *env)
{
	if (verify_arguments(env) == 1)
		return (error(1));
	env->mlx = mlx_init();
	env->zoom = 650;
	env->sx = 2560;
	env->sy = 1418;
	env->jx = 0;
	env->jy = 0;
	env->mx = 0;
	env->my = 0;
	env->mfactor = 1;
	env->zfactor = 0.0;
	env->r = 255;
	env->g = 255;
	env->b = 255;
	env->p = 0;
	env->locked = 0;
	if ((env->win_main = mlx_new_window(env->mlx, env->sx, env->sy, "Fract'ol")) == NULL)
			return (error(2));
	mlx_key_hook(env->win_main, esc_handler, env);
	mlx_hook(env->win_main, DestroyNotify, StructureNotifyMask, destroy_handler, env);
	mlx_hook(env->win_main, ButtonPress, ButtonPressMask, mouse_hooks, env);
	mlx_hook(env->win_main, KeyPress, KeyPressMask, key_hooks, env);
	mlx_hook(env->win_main, MotionNotify, PointerMotionMask, julia_param, env);
	if (draw_fractal(env) == 1)
		return (1);
	mlx_loop(env->mlx);
	return (0);
}

int		main(int argc, char **argv)
{
	t_env env;

	if (argc != 2)
		return (error(0));
	env.fract = argv[1];
	env.params = argc;
	if (env_init(&env) == 1)
		return (1);
	return (0);
}
