/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessadik <aessadik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:05:00 by aessadik          #+#    #+#             */
/*   Updated: 2024/05/12 16:39:24 by aessadik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/fractol.h"


void pixel_put(t_mlx *data, int x, int y, int clr)
{
	char *s;

	s = data->test.addr + (y * data->test.line + x * (data->test.bpp / 8));
	*(unsigned int *)s = clr;
}
void window_m(t_mlx *vars, char **av)
{
	vars->mlx = mlx_init();
	vars->mlx_w = mlx_new_window(vars->mlx, H, W, *av + 2);
	vars->test.im = mlx_new_image(vars->mlx, W, H);
	vars->test.addr = mlx_get_data_addr(vars->test.im, &vars->test.bpp, &vars->test.line, &vars->test.end);
	draw_m(vars);
	mlx_put_image_to_window(vars->mlx, vars->mlx_w, vars->test.im, 0, 0);
	mlx_mouse_hook(vars->mlx_w, mouse, vars);
	mlx_key_hook(vars->mlx_w, keycheck, vars);
	mlx_hook(vars->mlx_w, 17, 0, c ,vars);
	mlx_loop(vars->mlx);
}
void window_j(t_mlx *vars, char **av, double real, double imagine)
{
	vars->mlx = mlx_init();
	vars->mlx_w = mlx_new_window(vars->mlx, H, W, *av + 2);
	vars->test.im = mlx_new_image(vars->mlx, W, H);
	vars->test.addr = mlx_get_data_addr(vars->test.im, &vars->test.bpp, &vars->test.line, &vars->test.end);
	draw_j(vars, real, imagine);
	mlx_put_image_to_window(vars->mlx, vars->mlx_w, vars->test.im, 0, 0);
	mlx_mouse_hook(vars->mlx_w, mousej, vars);
	mlx_key_hook(vars->mlx_w, keycheckj, vars);
	mlx_hook(vars->mlx_w, 17, 0, c ,vars);
	mlx_loop(vars->mlx);
}



