/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoquel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 13:26:30 by achoquel          #+#    #+#             */
/*   Updated: 2019/02/06 15:05:05 by achoquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include "../srcs/libft/includes/libft.h"

typedef struct	s_env
{
	void	*mlx;
	void	*win_main;
	char	*fract;
	int		closed;
	int		sx;
	int		sy;
	int		params;
	void	*img;
	int		*data;
	int		bpp;
	int		size_l;
	int		endian;
	int		*xpmx;
	int		*xpmy;
	double	zoom;
	double		mx;
	double		my;
	double		jx;
	double		jy;
	int			r;
	int			g;
	int			b;
	int			d;
}				t_env;

typedef struct	s_mandelbrot
{
	int		x;
	int		y;
	double	x1;
	double	y1;
	double	zoom;
	double	iter;
	double	z_r;
	double	z_i;
	double	c_r;
	double	c_i;
	double	tmp;
	double	i;
}				t_mandelbrot;

int	error(int code);
int	verify_arguments(t_env *env);
int	draw_fractal(t_env *env);
int	mandelbrot(t_env *env);
int	julia(t_env *env);
int	burning(t_env *env);
int mouse_hooks(int key, int x, int y, t_env *env);
int key_hooks(int key, t_env *env);


#endif
