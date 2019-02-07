/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoquel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 10:56:24 by achoquel          #+#    #+#             */
/*   Updated: 2019/02/06 15:44:06 by achoquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

/*
**                  BURNING SHIP ALGORITHM
** Exact same as Mandelbrot one, but it is done with the absolute value
** of Z instead of - or + value
*/

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
		m->x = 0;
		m->y = 0;
		m->zoom = env->zoom;
		m->x1 = -(13.5 / (m->zoom / 100.0)) + (env->mx / (m->zoom / 10));
		m->y1 = -(10.5 / (m->zoom / 100.0)) + (env->my / (m->zoom / 10));
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

int		burning_color(double a, t_env *env)
{
	int	r;
	int	g;
	int	b;
	int	c;

	env->r = 0;
	r = (a * 0);
	g = (0 - (a * 0));
	b = (255 - (a * 10));
	c = (r << 16) + (g << 8) + b;
	return (c);

}

int		burning(t_env *env)
{
	t_mandelbrot m;

	if (burning_init(&m, env, 0) == 1)
		return (1);
	while (m.x < env->sx)
	{
		while (m.y < env->sy)
		{
			burning_init(&m, env, 1);
			while (fabs(m.z_r) * fabs(m.z_r) + fabs(m.z_i) * fabs(m.z_i) < 4 && m.i < m.iter)
			{
				m.tmp = m.z_r;
				m.z_r = fabs(m.z_r) * fabs(m.z_r) - fabs(m.z_i) * fabs(m.z_i) + m.c_r;
				m.z_i = 2 * fabs(m.tmp) * fabs(m.z_i) + m.c_i;
				m.i++;
				env->data[m.y * env->sx + m.x] = burning_color(m.i, env);
			}
			m.y++;
		}
		m.y = 0;
		m.x++;
	}
	mlx_put_image_to_window(env->mlx, env->win_main, env->img, 0, 0);
	mlx_destroy_image(env->mlx, env->img);
	return (0);
}

