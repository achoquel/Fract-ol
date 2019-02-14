/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoquel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 10:54:54 by achoquel          #+#    #+#             */
/*   Updated: 2019/02/14 13:20:25 by achoquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

void	julia_param_init(t_env *env)
{
	if (ft_strcmp(env->fract, "Julia") == 0)
	{
		env->jx = -0.8;
		env->jy = 0.156;
	}
	else if (ft_strcmp(env->fract, "Juliabs") == 0)
	{
		env->jx = -0.113333;
		env->jy = 0.227273;
	}
}

int		julia_init(t_mandelbrot *m, t_env *env, int moment)
{
	if (moment == 1)
	{
		m->c_r = env->jx;
		m->c_i = env->jy;
		m->z_r = m->x / m->zoom + m->x1;
		m->z_i = m->y / m->zoom + m->y1;
		m->i = 0;
	}
	else
	{
		m->x = 500 - env->opti * 500;
		m->y = -1;
		m->zoom = env->zoom;
		m->x1 = env->x1;
		m->y1 = env->y1;
		m->iter = env->iter;
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

int		julia(t_env *env)
{
	t_mandelbrot m;

	if (julia_init(&m, env, 0) == 1)
		return (1);
	while (m.x < env->sx)
	{
		while (++m.y < env->sy)
		{
			julia_init(&m, env, 1);
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
	return (hud_master(env));
}
