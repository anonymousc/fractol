/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessadik <aessadik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 07:33:09 by aessadik          #+#    #+#             */
/*   Updated: 2024/05/12 16:46:05 by aessadik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/fractol.h"

int     keycheck(int keycode, t_mlx *test)
{
	double shift;
	double x_shift;
	double y_shift;

    if (keycode == 53)
        exit(0);
	else if(keycode == 40)
	{
		test->fracts.colors = 10;
	}
	else if(keycode == 39)
		test->fracts.colors = 10;
    else if (keycode == 123)
	{
		x_shift = get_x_value(test->fracts.x_max, test->fracts.x_min);
        test->fracts.x_max -= x_shift;
		test->fracts.x_min -= x_shift;
	}
	else if (keycode == 124)
	{
		x_shift = get_x_value(test->fracts.x_max, test->fracts.x_min);
        test->fracts.x_max += x_shift;
		test->fracts.x_min += x_shift;
	}
    else if (keycode == 126)
	{
		y_shift = get_y_value(test->fracts.y_max, test->fracts.y_min);
        test->fracts.y_max -= y_shift;
		test->fracts.y_min -= y_shift;
	}
    else if (keycode == 125)
	{
		y_shift = get_y_value(test->fracts.y_max, test->fracts.y_min);
        test->fracts.y_max += y_shift;
		test->fracts.y_min += y_shift;
	}
	render_fracts(test);
	return (0);
}
int     keycheckj(int keycode, t_mlx *test)
{
	double shift;
	double x_shift;
	double y_shift;

    if (keycode == 53)
        exit(0);
	else if(keycode == 40)
	{
		test->fracts.colors = 10;
	}
	else if(keycode == 39)
		test->fracts.colors = 10;
    else if (keycode == 123)
	{
		x_shift = get_x_value(test->fracts.x_max, test->fracts.x_min);
        test->fracts.x_max -= x_shift;
		test->fracts.x_min -= x_shift;
	}
	else if (keycode == 124)
	{
		x_shift = get_x_value(test->fracts.x_max, test->fracts.x_min);
        test->fracts.x_max += x_shift;
		test->fracts.x_min += x_shift;
	}
    else if (keycode == 126)
	{
		y_shift = get_y_value(test->fracts.y_max, test->fracts.y_min);
        test->fracts.y_max -= y_shift;
		test->fracts.y_min -= y_shift;
	}
    else if (keycode == 125)
	{
		y_shift = get_y_value(test->fracts.y_max, test->fracts.y_min);
        test->fracts.y_max += y_shift;
		test->fracts.y_min += y_shift;
	}
	render_fracts_j(test);
	return (0);
}
int mouse(int keycode,int x, int y,  t_mlx *test)
{
	double zoom_ratio_x = get_x_value(test->fracts.x_max, test->fracts.x_min);
	double zoom_ratio_y = get_x_value(test->fracts.y_max, test->fracts.y_min);
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
	return 0;
}
int mousej(int keycode,int x, int y,  t_mlx *test)
{
	double zoom_ratio_x = get_x_value(test->fracts.x_max, test->fracts.x_min);
	double zoom_ratio_y = get_x_value(test->fracts.y_max, test->fracts.y_min);
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
	return 0;
}
int c(void)
{
	exit(0);
}