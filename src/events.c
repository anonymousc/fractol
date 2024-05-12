/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessadik <aessadik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 07:33:09 by aessadik          #+#    #+#             */
/*   Updated: 2024/05/12 20:44:38 by aessadik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/fractol.h"

void	checks(t_mlx *test, double x_shift, double y_shift, int flag)
{
	if (flag == 1)
	{
		x_shift = get_x_value(test->fracts.x_max, test->fracts.x_min);
		test->fracts.x_max -= x_shift;
		test->fracts.x_min -= x_shift;
	}
	if (flag == 2)
	{
		x_shift = get_x_value(test->fracts.x_max, test->fracts.x_min);
		test->fracts.x_max += x_shift;
		test->fracts.x_min += x_shift;
	}
	if (flag == 3)
	{
		y_shift = get_y_value(test->fracts.y_max, test->fracts.y_min);
		test->fracts.y_max -= y_shift;
		test->fracts.y_min -= y_shift;
	}
}

int	keycheck(int keycode, t_mlx *test)
{
	double	x_shift;
	double	y_shift;

	x_shift = 0.0;
	y_shift = 0.0;
	if (keycode == 53)
		exit(0);
	else if (keycode == 123)
		checks(test, x_shift, y_shift, 1);
	else if (keycode == 124)
		checks(test, x_shift, y_shift, 2);
	else if (keycode == 126)
		checks(test, x_shift, y_shift, 3);
	else if (keycode == 125)
	{
		y_shift = get_y_value(test->fracts.y_max, test->fracts.y_min);
		test->fracts.y_max += y_shift;
		test->fracts.y_min += y_shift;
	}
	render_fracts(test);
	return (0);
}

int	keycheckj(int keycode, t_mlx *test)
{
	double	x_shift;
	double	y_shift;

	x_shift = 0.0;
	y_shift = 0.0;
	if (keycode == 53)
		exit(0);
	else if (keycode == 123)
		checks(test, x_shift, y_shift, 1);
	else if (keycode == 124)
		checks(test, x_shift, y_shift, 2);
	else if (keycode == 126)
		checks(test, x_shift, y_shift, 3);
	else if (keycode == 125)
	{
		y_shift = get_y_value(test->fracts.y_max, test->fracts.y_min);
		test->fracts.y_max += y_shift;
		test->fracts.y_min += y_shift;
	}
	render_fracts_j(test);
	return (0);
}

int	mouse(int keycode, int x, int y, t_mlx *test)
{
	double	zoom_ratio_x;
	double	zoom_ratio_y;

	x = 0;
	y = 0;
	zoom_ratio_x = get_x_value(test->fracts.x_max, test->fracts.x_min);
	zoom_ratio_y = get_x_value(test->fracts.y_max, test->fracts.y_min);
	if (keycode == 4)
	{
		test->fracts.x_max += zoom_ratio_x;
		test->fracts.x_min -= zoom_ratio_x;
		test->fracts.y_max += zoom_ratio_y;
		test->fracts.y_min -= zoom_ratio_y;
	}
	if (keycode == 5)
	{
		test->fracts.x_max -= zoom_ratio_x;
		test->fracts.x_min += zoom_ratio_x;
		test->fracts.y_max -= zoom_ratio_y;
		test->fracts.y_min += zoom_ratio_y;
	}
	render_fracts(test);
	return (0);
}

int	mousej(int keycode, int x, int y, t_mlx *test)
{
	double	zoom_ratio_x;
	double	zoom_ratio_y;

	x = 0;
	y = 0;
	zoom_ratio_x = get_x_value(test->fracts.x_max, test->fracts.x_min);
	zoom_ratio_y = get_x_value(test->fracts.y_max, test->fracts.y_min);
	if (keycode == 4)
	{
		test->fracts.x_max += zoom_ratio_x;
		test->fracts.x_min -= zoom_ratio_x;
		test->fracts.y_max += zoom_ratio_y;
		test->fracts.y_min -= zoom_ratio_y;
	}
	if (keycode == 5)
	{
		test->fracts.x_max -= zoom_ratio_x;
		test->fracts.x_min += zoom_ratio_x;
		test->fracts.y_max -= zoom_ratio_y;
		test->fracts.y_min += zoom_ratio_y;
	}
	render_fracts_j(test);
	return (0);
}
