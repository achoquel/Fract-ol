/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoquel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 11:05:37 by achoquel          #+#    #+#             */
/*   Updated: 2019/02/06 15:11:05 by achoquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

int		no_fractal(t_env *env)
{
	if ((env->img = mlx_xpm_file_to_image(env->mlx, "./img/fractol.xpm", &env->size_l, &env->bpp)) == NULL)
		return (error(3));
	mlx_put_image_to_window(env->mlx, env->win_main, env->img, 0, 0);
	mlx_destroy_image(env->mlx, env->img);
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
	else if (ft_strcmp(env->fract, "NULL") == 0 && env->params == 1)
		return (no_fractal(env));
	return (0);
}

int		env_init(t_env *env)
{
	if (verify_arguments(env) == 1)
		return (error(1));
	env->mlx = mlx_init();
	env->zoom = 650;
	env->sx = 2560;
	env->sy = 1440;
	env->mx = 0;
	env->my = 0;
	env->r = 255;
	env->g = 255;
	env->b = 255;
	if ((env->win_main = mlx_new_window(env->mlx, env->sx, env->sy, "Fract'ol")) == NULL)
			return (error(2));
	mlx_key_hook(env->win_main, key_hooks, env);
	mlx_mouse_hook(env->win_main, mouse_hooks, env);
	if (draw_fractal(env) == 1)
		return (1);
	mlx_loop(env->mlx);
	return (0);
}

int		main(int argc, char **argv)
{
	t_env env;

	if (argc > 2)
		return (error(0));
	if (argc == 2)
		env.fract = argv[1];
	else
		env.fract = "NULL";
	env.params = argc;
	if (env_init(&env) == 1)
		return (1);
	return (0);
}
