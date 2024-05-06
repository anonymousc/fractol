/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessadik <aessadik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 21:50:05 by aessadik          #+#    #+#             */
/*   Updated: 2024/05/06 21:23:27 by aessadik         ###   ########.fr       */
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
void draw(t_mlx *test1)
{
	// int x;
	// int y;
	// int col;
	t_fract keys;
	t_complex z;
	
	printf("draw called\n");
	// col = 0;
	keys.cy = 0;
	printf(" test->x_max %f", test1->fracts.x_max);
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
	

