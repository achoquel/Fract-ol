/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoquel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 11:05:37 by achoquel          #+#    #+#             */
/*   Updated: 2019/02/14 13:21:16 by achoquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

int		hud(t_env *env)
{
	char	*t1;
	char	*t2;

	t1 = ft_itoa(env->mfactor);
	t2 = ft_itoa(env->iter);
	if ((env->img = mlx_xpm_file_to_image(env->mlx, "./img/ath.xpm",
		&env->size_l, &env->bpp)) == NULL)
		return (error(3));
	mlx_put_image_to_window(env->mlx, env->win_main, env->img, 0, 0);
	mlx_destroy_image(env->mlx, env->img);
	mlx_string_put(env->mlx, env->win_main, 210, 1222, 0xFFFFFF, env->fract);
	mlx_string_put(env->mlx, env->win_main, 210, 1255, 0xFFFFFF, t1);
	mlx_string_put(env->mlx, env->win_main, 210, 1288, 0xFFFFFF, t2);
	mlx_string_put(env->mlx, env->win_main, 210, 1320, 0xFFFFFF,
	get_palette(env));
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
	else if (ft_strcmp(env->fract, "Mandelbar") == 0)
		return (mandelbar(env));
	else if (ft_strcmp(env->fract, "Juliabs") == 0)
		return (juliabs(env));
	return (0);
}

void	vars_init(t_env *env)
{
	if (env->opti == 0)
	{
		env->zoom = 650;
		env->sx = 2560;
		env->sy = 1440;
		fract_init(env);
	}
	else
	{
		env->zoom = 200;
		env->sx = 600;
		env->sy = 400;
		fract_initopti(env);
	}
	julia_param_init(env);
	env->mx = 0;
	env->my = 0;
	env->mfactor = 1.0;
	env->zfactor = 0.0;
	env->p = 0;
	env->locked = 1;
}

int		env_init(t_env *env)
{
	if (verify_arguments(env) == 1)
		return (error(1));
	env->mlx = mlx_init();
	vars_init(env);
	if ((env->win_main = mlx_new_window(env->mlx, env->sx, env->sy, "Fract'ol"))
		== NULL)
		return (error(2));
	mlx_key_hook(env->win_main, esc_handler, env);
	mlx_hook(env->win_main, DESTROYNOTIFY, STRUCTUREMODIFYMASK, destroy_handler,
			env);
	mlx_hook(env->win_main, BUTTONPRESS, BUTTONPRESSMASK, mouse_hooks, env);
	mlx_hook(env->win_main, KEYPRESS, KEYPRESSMASK, key_hooks, env);
	mlx_hook(env->win_main, MOTIONNOTIFY, POINTERMOTIONMASK, julia_param, env);
	if (draw_fractal(env) == 1)
		return (1);
	mlx_loop(env->mlx);
	return (0);
}

int		main(int argc, char **argv)
{
	t_env env;

	if (argc < 2 || argc > 3)
		return (error(0));
	if (argc == 3 && ft_strcmp(argv[2], "-optimized") != 0)
		return (error(4));
	env.fract = argv[1];
	if (argc == 3)
		env.opti = 1;
	else
		env.opti = 0;
	if (env_init(&env) == 1)
		return (1);
	return (0);
}
