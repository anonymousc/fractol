/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessadik <aessadik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 21:50:05 by aessadik          #+#    #+#             */
/*   Updated: 2024/05/06 19:18:43 by aessadik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/fractol.h"

int mandelbrot(t_complex c)
{
	t_fract fracts;
	t_complex z;
	z.imag = 0;
	z.real = 0;
	int i = 0;
	fracts.iter = 100;
	double tmp;
	while (i < fracts.iter)
	{
		tmp  = z.real * z.real - z.imag * z.imag + c.real;
       	z.imag = 2 * z.real * z.imag + c.imag;
      	z.real = tmp;
	
		if ((z.real * z.real + z.imag * z.imag) > 4){
		  	return (coloring(i));}
		i++;
	}	
	return (0);
}
int julia(t_complex c, t_complex z)
{
	t_fract fracts;
	z.imag = 0;
	z.real = 0;
	int i = 0;
	fracts.iter = 100;
	double tmp;
	while (i < fracts.iter)
	{
		tmp  = z.real * z.real - z.imag * z.imag + 0.3;
       	z.imag = 2 * z.real * z.imag + 0.2;
      	z.real = tmp;
	
		if ((z.real * z.real + z.imag * z.imag) > 4){
		  	return (coloring(i));}
		i++;
	}	
	return (0);
}
void draw(t_mlx test ,t_dat *img, t_fract *test1)
{
	int x;
	int y;
	int col;
	t_fract keys;
	t_complex z;
	
	col = 0;
	y = 0;
	mlx_clear_window(&test, test.mlx_w);
	while (keys.cy < H)
	{
		keys.cx = 0;
		while (keys.cx < W)
		{
			z.real = scale(keys.cx, W, -2.0,2.0) +  test1->key_x;
			z.imag = scale(keys.cy, W, -2.0 ,2.0) +  test1->key_y;
			int color = mandelbrot(z);
			pixel_put(img, keys.cx, keys.cy, color);
			keys.cx++;
		}
		keys.cy++;
	}
}
// void draw_j(t_dat *img)
// {
// 	int x;
// 	int y;
// 	int col;
// 	t_fract keys;
// 	t_complex z;
// 	t_complex c;
	
// 	col = 0;
// 	y = 0;
// 	while (keys.cy < H)
// 	{
// 		keys.cx = 0;
// 		while (keys.cx < W)
// 		{
// 			z.real = scale(keys.zx, W, -2.0,2.0);
// 			z.imag = scale(keys.zy, W, -2.0 ,2.0);
// 			c.imag = scale(keys.cy, W, -2.0 ,2.0);
// 			c.real = scale(keys.cy, W, -2.0 ,2.0);
// 			int color = julia(c, z);
// 			pixel_put(img, keys.cx, keys.cy, color);
// 			keys.cx++;
// 		}
// 		keys.cy++;
// 	}
// }
	

