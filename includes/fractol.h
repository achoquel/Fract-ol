/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoquel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 13:26:30 by achoquel          #+#    #+#             */
/*   Updated: 2019/02/13 13:33:52 by achoquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include "../srcs/libft/includes/libft.h"

# define KEYPRESSMASK (1L<<0)
# define BUTTONPRESSMASK (1L<<2)
# define POINTERMOTIONMASK (1L<<6)
# define STRUCTUREMODIFYMASK (1L<<17)
# define KEYPRESS 2
# define BUTTONPRESS 4
# define MOTIONNOTIFY 6
# define DESTROYNOTIFY 17
# define MZR m.z_r
# define MZI m.z_i
# define MCR m.c_r
# define MCI m.c_i
# define MI m.i
# define IT m.iter

typedef struct	s_env
{
	void		*mlx;
	void		*win_main;
	char		*fract;
	int			closed;
	int			sx;
	int			sy;
	int			params;
	void		*img;
	int			*data;
	int			bpp;
	int			size_l;
	int			endian;
	double		zoom;
	double		mx;
	double		my;
	double		jx;
	double		jy;
	int			mfactor;
	double		zfactor;
	int			locked;
	int			p;
	double		zx;
	double		zy;
	int			x;
	int			y;
	double		x1;
	double		y1;
	double		iter;
	double		z_r;
	double		z_i;
	double		c_r;
	double		c_i;
	double		tmp;
	double		i;

}				t_env;

typedef struct	s_mandelbrot
{
	int			x;
	int			y;
	double		x1;
	double		y1;
	double		zoom;
	double		iter;
	double		z_r;
	double		z_i;
	double		c_r;
	double		c_i;
	double		tmp;
	double		i;
}				t_mandelbrot;

int				error(int code);
int				verify_arguments(t_env *env);
int				draw_fractal(t_env *env);
int				mandelbrot(t_env *env);
int				julia(t_env *env);
int				burning(t_env *env);
int				eye(t_env *env);
int				douady(t_env *env);
int				dendrite(t_env *env);
int				mouse_hooks(int key, int x, int y, t_env *env);
int				key_hooks(int key, t_env *env);
int				esc_handler(int key, t_env *env);
int				destroy_handler(t_env *env);
int				julia_param(int x, int y, t_env *env);
int				hud(t_env *env);
int				palette(int p, int zn, int iter, int max);
char			*get_palette(t_env *env);
int				move_handler(int key, t_env *env);
int				fractal_changer(int key, t_env *env);
int				theme_handler(t_env *env);
int				reset_handler(t_env *env);
void			fract_init(t_env *env);
void			zoom_handler(t_env *env, int x, int y, int key);

#endif
