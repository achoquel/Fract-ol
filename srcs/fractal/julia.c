/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoquel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 10:54:54 by achoquel          #+#    #+#             */
/*   Updated: 2019/02/06 15:08:59 by achoquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

/*
** Julia drawing algorithm is the same than Mandelbrot's one, except the c_r
** and c_i varies.
*/

int		julia_init(t_mandelbrot *m, t_env *env, int moment)
{
	if (moment == 1)
	{
		m->c_r = 0.285;
		m->c_i = 0.01;
		m->z_r = m->x / m->zoom + m->x1;
		m->z_i = m->y / m->zoom + m->y1;
		m->i = 0;
	}
	else
	{
		m->x = 0;
		m->y = 0;
		m->zoom = env->zoom;
		m->x1 = -(13.0 / (m->zoom / 100.0)) + (env->mx / (m->zoom / 10));
		m->y1 = -(6.6 / (m->zoom / 100.0)) + (env->my / (m->zoom / 10));
		m->iter = 150;
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

int		julia_color(double i, t_env *env)
{
	int	r;
	int	g;
	int	b;
	int	c;

	r = (i * 5) * env->r;
	g = (255 - (i * 15)) * env->g;
	b = (255 - (i * 35)) * env->b;
	c = (r << 16) + (g << 8) + b;
	return (c);
}

int		julia(t_env *env)
{
	t_mandelbrot m;

	if (julia_init(&m, env, 0) == 1)
		return (1);
	while (m.x < env->sx)
	{
		while (m.y < env->sy)
		{
			julia_init(&m, env, 1);
			while (m.z_r * m.z_r + m.z_i * m.z_i < 4 && m.i < m.iter)
			{
				m.tmp = m.z_r;
				m.z_r = m.z_r * m.z_r - m.z_i * m.z_i + m.c_r;
				m.z_i = 2 * m.tmp * m.z_i + m.c_i;
				m.i++;
				env->data[m.y * env->sx + m.x] = julia_color(m.i, env);
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
