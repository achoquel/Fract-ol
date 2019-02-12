/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoquel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 10:52:34 by achoquel          #+#    #+#             */
/*   Updated: 2019/02/12 16:07:34 by achoquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

static int	mandel_init(t_mandelbrot *m, t_env *env, int moment)
{
	if (moment == 1)
	{
		m->c_r = m->x / m->zoom + m->x1;
		m->c_i = m->y / m->zoom + m->y1;
		m->z_r = 0;
		m->z_i = 0;
		m->i = 0;
	}
	else
	{
		m->x = 500;
		m->y = -1;
		m->zoom = env->zoom;
		m->x1 = -(18.5 / (m->zoom / 100.0)) + (env->mx / (m->zoom / 10));
		m->y1 = -(6.8 / (m->zoom / 100.0)) + (env->my / (m->zoom / 10));
		m->iter = 50;
		m->z_r = 0;
		m->z_i = 0;
		m->i = 0;
		if ((env->img = mlx_new_image(env->mlx, env->sx, env->sy)) == NULL)
			return (error(3));
		env->data = (int *)mlx_get_data_addr(env->img, &env->bpp, &env->size_l,
				&env->endian);
	}
	return (0);
}

int			mandelbrot(t_env *env)
{
	t_mandelbrot m;

	if (mandel_init(&m, env, 0) == 1)
		return (1);
	while (m.x < env->sx)
	{
		while (++m.y < env->sy)
		{
			mandel_init(&m, env, 1);
			while (m.z_r * m.z_r + m.z_i * m.z_i < 4 && m.i < m.iter)
			{
				m.tmp = m.z_r;
				m.z_r = m.z_r * m.z_r - m.z_i * m.z_i + m.c_r;
				m.z_i = 2 * m.tmp * m.z_i + m.c_i;
				m.i++;
				env->data[m.y * env->sx + m.x] = palette(env->p, (m.z_r + m.z_i)
				, m.i, m.iter);
			}
		}
		m.y = -1;
		m.x++;
	}
	mlx_put_image_to_window(env->mlx, env->win_main, env->img, 0, 0);
	mlx_destroy_image(env->mlx, env->img);
	return (hud(env));
}
