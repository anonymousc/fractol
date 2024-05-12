/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessadik <aessadik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:55:34 by aessadik          #+#    #+#             */
/*   Updated: 2024/05/12 20:49:58 by aessadik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/fractol.h"

void	render_fracts(t_mlx *test)
{
	draw_m(test);
	mlx_put_image_to_window(test->mlx, test->mlx_w, test->test.im, 0, 0);
}

void	render_fracts_j(t_mlx *test)
{
	draw_j(test, test->c_real, test->c_imag);
	mlx_put_image_to_window(test->mlx, test->mlx_w, test->test.im, 0, 0);
}

double	get_x_value(double x_max, double x_min)
{
	double	x_ratio;

	x_ratio = (x_max - x_min) / W;
	x_ratio *= 100;
	return (x_ratio);
}

double	get_y_value(double y_max, double y_min)
{
	double	y_ratio;

	y_ratio = (y_max - y_min) / H;
	y_ratio *= 100;
	return (y_ratio);
}

int	coloring(int iterations)
{
	double	x;
	int		red;
	int		blue;
	int		green;

	x = (double)iterations / 255.0;
	red = (int)(9 * (1 - x) * x * x * x * 255);
	green = (int)(15 * (1 - x) * (1 - x) * x * x * 255);
	blue = (int)(8.5 * (1 - x) * (1 - x) * (1 - x) * x * 255);
	return ((red << 16) + (green << 8) + blue);
}
