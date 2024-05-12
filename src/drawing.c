/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessadik <aessadik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 13:46:40 by aessadik          #+#    #+#             */
/*   Updated: 2024/05/12 04:00:08 by aessadik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/fractol.h"

void draw_j(t_mlx *test1, double real, double imagine)
{
	t_fract keys;
	t_complex z;
	keys.cy = 0;
	while (keys.cy < H)
	{
		keys.cx = 0;
		while (keys.cx < W)
		{
			z.real = scale(keys.cx, W,test1->fracts.x_min , test1->fracts.x_max);
			z.imag = scale(keys.cy, W, test1->fracts.y_min , test1->fracts.y_max);
			int color = julia(&z, real, imagine);
			pixel_put(test1, keys.cx, keys.cy, color);
			keys.cx++;
		}
		keys.cy++;
	}
}
void draw_m(t_mlx *test1)
{
	t_fract keys;
	t_complex z;
	keys.cy = 0;
	while (keys.cy < H)
	{
		keys.cx = 0;
		while (keys.cx < W)
		{
			z.real = scale(keys.cx, W,test1->fracts.x_min , test1->fracts.x_max);
			z.imag = scale(keys.cy, W, test1->fracts.y_min , test1->fracts.y_max);
			int color = mandelbrot(z);
			pixel_put(test1, keys.cx, keys.cy, color);
			keys.cx++;
		}
		keys.cy++;
	}
}