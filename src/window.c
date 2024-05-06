/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessadik <aessadik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:05:00 by aessadik          #+#    #+#             */
/*   Updated: 2024/05/06 21:27:43 by aessadik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "../lib/fractol.h"

int     keycheck(int keycode, t_mlx *test)
{
	printf("was called\n");
    if (keycode == 53)
        exit(0);
    else if (keycode == 123)
	{
        test->fracts.x_max -= 0.2;
		test->fracts.x_min -= 0.2;
	}
	else if (keycode == 124)
	{
        test->fracts.x_max += 0.2;
		test->fracts.x_min += 0.2;
	}
    else if (keycode == 126)
	{
        test->fracts.y_max -= 0.2;
		test->fracts.y_min -= 0.2;
	}
    else if (keycode == 125)
	{
        test->fracts.y_max += 0.2;
		test->fracts.y_min += 0.2;
	}
	printf("xmax %d\n", test->fracts.x_max);
	mlx_destroy_image(test->mlx, test->test.im);
	test->test.im = mlx_new_image(test->mlx, W, H);
	draw(test);
	mlx_put_image_to_window(test->mlx, test->mlx_w, test->test.im, 0, 0);
	//printf("test %f\n", test->key_x);
	return (0);
}
int c(void)
{
	exit(0);
	return 1;
}
void pixel_put(t_mlx *data, int x, int y, int clr)
{
	char *s;
	
	s = data->test.addr + (y * data->test.line + x * (data->test.bpp / 8));
	*(unsigned int *)s = clr;
}
void window(t_mlx *vars, char **av)
{
	//t_dat img;
	//t_fract *test = malloc(sizeof(t_fract));
	t_complex c1;
	vars->mlx = mlx_init();
	vars->mlx_w = mlx_new_window(vars->mlx, H, W, *av + 2);
	vars->test.im = mlx_new_image(vars->mlx, W, H);
	vars->test.addr = mlx_get_data_addr(vars->test.im, &vars->test.bpp, &vars->test.line, &vars->test.end);
	draw(vars);
	mlx_put_image_to_window(vars->mlx, vars->mlx_w, vars->test.im, 0, 0);
	mlx_key_hook(vars->mlx_w, keycheck, vars);
	// draw(vars ,&img, test);
	// mlx_put_image_to_window(vars->mlx, vars->mlx_w, img.im, 0, 0);
	mlx_hook(vars->mlx_w, 17, 0, c ,vars);
	mlx_loop(vars->mlx);
   //free(&vars);
}

int main(int ac , char **av)
{
	t_mlx var;
	var.fracts.x_max = 2;
	var.fracts.x_min = -2;
	var.fracts.y_max = 2;
	var.fracts.y_min = -2;
	window(&var, av);
}


