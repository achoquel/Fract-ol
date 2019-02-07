/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoquel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 10:52:34 by achoquel          #+#    #+#             */
/*   Updated: 2019/02/07 16:46:15 by achoquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

/*
 **                    MANDELBROT DRAWING ALGORITHM
 **
 ** Formula : Zn+1 = Zn^2 + Z0
 ** We're going to create a complex number called Z to use X and Y
 ** So, Z = X + i*Y.
 ** A complex number is a number with a real part (here X) and an imaginary part
 ** (here i * Y). The particularity of theses numbers is that i * i = -1.
 ** We modify Z in our base formula :
 **    Zn+1 = Xn^2 + 2i * Xn * Yn + i^2 * Yn^2 + X0 + i * Y0
 ** => Zn+1 = Xn^2 - Yn^2 + X0 + i (2 * Xn * Yn + Y0)
 **           -----------------  --------------------
 **               real part          imaginary part
 ** To know the color of the point, we look his module
 **  A module is calculated with the following formula :
 ** sqrt(X^2 + Y^2);
 **
 ** We calculate the module of Zn :
 ** sqrt(Xn+1 ^ 2 + Yn+1 ^ 2)
 ** If the point is part of the fractal, its module should be less than 2 
 ** after x iterations
 ** So sqrt(Xn+1 ^ 2 + Yn+1 ^ 2) < 2
 ** We can simplify this :
 ** Xn+1 ^ 2 + Yn+1 ^ 2 < 4
 **
 ** Here, z_r is the real part of Z and z_i the imaginary part of Z.
 ** c_r is the real part of Z0 and c_i the imaginary part of Z0.
 */

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
		m->x = 0;
		m->y = 0;
		m->zoom = env->zoom;
		m->x1 = -(13.5 / (m->zoom / 100.0)) + (env->mx / (m->zoom / 10));
		m->y1 = -(6.8 / (m->zoom / 100.0)) + (env->my / (m->zoom / 10));
		m->iter = 70;
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

static int	mandel_color(double a, t_env *env)
{
	int	r;
	int	g;
	int	b;
	int	c;

	if (a == 70)
		return (0x000000);
	(void)env;
	r = 255 - a * 2;
	g = 255 - a * 5;
	b = 255 - a * 7;
	c = (r << 16) + (g << 8) + b;
	return (c);
}

int			mandelbrot(t_env *env)
{
	t_mandelbrot m;

	if (mandel_init(&m, env, 0) == 1)
		return (1);
	while (m.x < env->sx)
	{
		while (m.y < env->sy)
		{
			mandel_init(&m, env, 1);
			while (m.z_r * m.z_r + m.z_i * m.z_i < 4 && m.i < m.iter)
			{
				m.tmp = m.z_r;
				m.z_r = m.z_r * m.z_r - m.z_i * m.z_i + m.c_r;
				m.z_i = 2 * m.tmp * m.z_i + m.c_i;
				m.i++;
				env->data[m.y * env->sx + m.x] = mandel_color(m.i, env);
			}
			m.y++;
		}
		m.y = 0;
		m.x++;
	}
	mlx_put_image_to_window(env->mlx, env->win_main, env->img, 0, 0);
	mlx_destroy_image(env->mlx, env->img);
	return (hud(env));
}
