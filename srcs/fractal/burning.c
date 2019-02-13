/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoquel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 10:56:24 by achoquel          #+#    #+#             */
/*   Updated: 2019/02/13 16:05:52 by achoquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

int		burning_init(t_mandelbrot *m, t_env *env, int moment)
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
		m->x = 500 - 500 * env->opti;
		m->y = -1;
		m->zoom = env->zoom;
		m->x1 = env->x1;
		m->y1 = env->y1;
		m->iter = 64;
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

int		burning(t_env *env)
{
	t_mandelbrot m;

	if (burning_init(&m, env, 0) == 1)
		return (1);
	while (m.x < env->sx)
	{
		while (++m.y < env->sy)
		{
			burning_init(&m, env, 1);
			while (fabs(MZR) * fabs(MZR) + fabs(MZI) * fabs(MZI) < 4 && MI < IT)
			{
				m.tmp = m.z_r;
				m.z_r = fabs(MZR) * fabs(MZR) - fabs(MZI) * fabs(MZI) + m.c_r;
				m.z_i = 2 * fabs(m.tmp) * fabs(m.z_i) + m.c_i;
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
	return (hud_master(env));
}
