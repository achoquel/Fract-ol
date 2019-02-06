/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoquel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 10:59:28 by achoquel          #+#    #+#             */
/*   Updated: 2019/02/06 14:40:14 by achoquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"
#include <stdio.h>

int		error(int code)
{
	if (code == 0)
	{
		printf("\033[36m[USAGE] ./fractol {Fractal}\n");
		printf("\033[36mAvailable Fractals :\n");
		printf("\033[36m- Mandelbrot\n- Julia\n- BurningShip\n- Bidule\033[0m\n");
	}
	else if (code == 1)
		printf("\033[22;31m[ERROR] Wrong Fractal !\033[0m\n");
	else if (code == 2)
		printf("\033[22;31m[ERROR] Window creation has failed !\033[0m\n");
	else if (code == 3)
		printf("\033[22;31m[ERROR] Image creation has failed !\033[0m\n");
	return (1);
}

int		verify_arguments(t_env *env)
{
	if (ft_strcmp(env->fract, "BurningShip") != 0
	&& ft_strcmp(env->fract, "Julia") != 0
	&& ft_strcmp(env->fract, "Mandelbrot") != 0
	&& ft_strcmp(env->fract, "NULL") != 0)
		return (1);
	return (0);
}

