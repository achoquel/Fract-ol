/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palette2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoquel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 15:31:23 by achoquel          #+#    #+#             */
/*   Updated: 2019/02/11 17:01:28 by achoquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

/*
** P0 : Black and White
** P1 : Glow Red
** P2 : Glow Green
** P3 : Glow Blue
** P4 : Glow White
** P5 : Geometric Red
** P6 : Geometric Green
** P7 : Geometric Blue
** P8 : Geometric Cyan
** P9 : Geometric Magenta
** P10 :
** P11 :
** P12 :
** P13 :
** P14 :
** P15 :
*/

char	*get_palette2(t_env *env)
{
	if (env->p == 11)
		return ("Geometric White");
	else if (env->p == 12)
		return ("Circular Blue");
	else if (env->p == 13)
		return ("Circular Yellow/White");
	else if (env->p == 14)
		return ("Confettis");
	else
		return ("Confettis 2");
}

char	*get_palette(t_env *env)
{
	if (env->p == 0)
		return ("Black & White");
	else if (env->p == 1)
		return ("Glow Red");
	else if (env->p == 2)
		return ("Glow Green");
	else if (env->p == 3)
		return ("Glow Blue");
	else if (env->p == 4)
		return ("Glow White");
	else if (env->p == 5)
		return ("Geometric Red");
	else if (env->p == 6)
		return ("Geometric Green");
	else if (env->p == 7)
		return ("Geometric Blue");
	else if (env->p == 8)
		return ("Geometric Cyan");
	else if (env->p == 9)
		return ("Geometric Magenta");
	else if (env->p == 10)
		return ("Geometric Yellow");
	else
		return (get_palette2(env));
}

int		palette2(int p, int zn, int iter)
{
	if (p == 10)
		return (((255 - iter * zn) << 16) | ((255 - iter * zn) << 8) | (0));
	else if (p == 11)
		return (((255 - iter * zn) << 16) | ((255 - iter * zn) << 8) | (255 - iter * zn));
	else if (p == 12)
		return (0x0000FF * (iter + 1 - tan(abs(zn))/sqrt(2)));
	else if (p == 13)
		return (0xFFFFFF / cos(abs(zn)));
	else if (p == 14)
		return (0xFFFFFF / (- tan(iter / acos(abs(zn)) + log(2) * asin(zn))));
	else
		return (0xFFFFFF / (- cos(iter / asin(abs(zn)) + log(2) * atan(zn))));
}

int		palette(int p, int zn, int iter, int max)
{
	if (iter == max && p < 12)
		return (0x000000);
	else if (p == 0)
		return (0xFFFFFF);
	else if (p == 1)
		return (((iter * 5) << 16) | ((0) << 8) | (0));
	else if (p == 2)
		return (((0) << 16) | ((iter * 5) << 8) | (0));
	else if (p == 3)
		return (((0) << 16) | ((0) << 8) | (iter * 5));
	else if (p == 4)
		return (((iter * 5) << 16) | ((iter * 5) << 8) | (iter * 5));
	else if (p == 5)
		return (((255 - iter * zn) << 16) | ((0) << 8) | (0));
	else if (p == 6)
		return (((0) << 16) | ((255 - iter * zn) << 8) | (0));
	else if (p == 7)
		return (((0) << 16) | ((0) << 8) | (255 - iter * zn));
	else if (p == 8)
		return (((0) << 16) | ((255 - zn * iter) << 8) | (255 - zn * iter));
	else if (p == 9)
		return (((255 - zn * iter) << 16) | ((0) << 8) | (255 - zn * iter));
	else
		return (palette2(p, zn, iter));
}
