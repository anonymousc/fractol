/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessadik <aessadik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:55:34 by aessadik          #+#    #+#             */
/*   Updated: 2024/05/10 20:50:24 by aessadik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/fractol.h"

void	render_fracts(t_mlx *test)
{

	mlx_destroy_image(test->mlx, test->test.im);
	test->test.im = mlx_new_image(test->mlx, W, H);
	draw_m(test);
	mlx_put_image_to_window(test->mlx, test->mlx_w, test->test.im, 0, 0);
}
void	render_fracts_j(t_mlx *test)
{
	double real;
	double imag;
	mlx_destroy_image(test->mlx, test->test.im);
	test->test.im = mlx_new_image(test->mlx, W, H);
	draw_j(test, real , imag);
	mlx_put_image_to_window(test->mlx, test->mlx_w, test->test.im, 0, 0);
}
double get_x_value(double x_max, double x_min)
{
	double x_ratio;

	x_ratio = (x_max - x_min) / W;
	x_ratio *= 100;
	return (x_ratio);
}
double get_y_value(double y_max, double y_min)
{
	double y_ratio;

	y_ratio = (y_max - y_min) / H;
	y_ratio *= 100;
	return (y_ratio);
}
int coloring(int iterations) 
{
    int dark_blue = 0x000033; 
    int sky_blue = 0x6699FF;


    float t = (float)iterations / 255.0;
    int r = (1 - t) * ((dark_blue >> 16) & 0xFF) + t * ((sky_blue >> 16) & 0xFF);
    int g = (1 - t) * ((dark_blue >> 8) & 0xFF) + t * ((sky_blue >> 8) & 0xFF);
    int b = (1 - t) * (dark_blue & 0xFF) + t * (sky_blue & 0xFF);

    return (r << 16) | (g << 8) | b;
}

  