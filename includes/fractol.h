/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoquel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 13:26:30 by achoquel          #+#    #+#             */
/*   Updated: 2019/02/07 16:56:48 by achoquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include "../srcs/libft/includes/libft.h"

# define NoEventMask 0L
# define KeyPressMask (1L<<0)
# define KeyReleaseMask (1L<<1)
# define ButtonPressMask (1L<<2)
# define ButtonReleaseMask (1L<<3)
# define EnterWindowMask (1L<<4)
# define LeaveWindowMask (1L<<5)
# define PointerMotionMask (1L<<6)
# define PointerMotionHintMask (1L<<7)
# define Button1MotionMask (1L<<8)
# define Button2MotionMask (1L<<9)
# define Button3MotionMask (1L<<10)
# define Button4MotionMask (1L<<11)
# define Button5MotionMask (1L<<12)
# define ButtonMotionMask (1L<<13)
# define KeymapStateMask (1L<<14)
# define ExposureMask (1L<<15)
# define VisibilityChangeMask (1L<<16)
# define StructureNotifyMask (1L<<17)
# define ResizeRedirectMask (1L<<18)
# define SubstructureNotifyMask (1L<<19)
# define SubstructureRedirectMask (1L<<20)
# define FocusChangeMask (1L<<21)
# define PropertyChangeMask (1L<<22)
# define ColormapChangeMask (1L<<23)
# define OwnerGrabButtonMask (1L<<24)

# define KeyPress 2
# define KeyRelease 3
# define ButtonPress 4
# define ButtonRelease 5
# define MotionNotify 6
# define EnterNotify 7
# define LeaveNotify 8
# define FocusIn 9
# define FocusOut 10
# define KeymapNotify 11
# define Expose 12
# define GraphicsExpose 13
# define NoExpose 14
# define VisibilityNotify 15
# define CreateNotify 16
# define DestroyNotify 17
# define UnmapNotify 18
# define MapNotify 19
# define MapRequest 20
# define ReparentNotify 21
# define ConfigureNotify 22
# define ConfigureRequest 23
# define GravityNotify 24
# define ResizeRequest 25
# define CirculateNotify 26
# define CirculateRequest 27
# define PropertyNotify 28
# define SelectionClear 29
# define SelectionRequest 30
# define SelectionNotify 31
# define ColormapNotify 32
# define ClientMessage 33
# define MappingNotify 34
# define GenericEvent 35
# define LASTEvent 36


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
	int			mfactor;
	int			zfactor;
	int			hidden;
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
int	palm(t_env *env);
int mouse_hooks(int key, int x, int y, t_env *env);
int key_hooks(int key, t_env *env);
int esc_handler(int key, t_env *env);
int julia_param(int x, int y, t_env *env);
int hud(t_env *env);

#endif
