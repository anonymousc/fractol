/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessadik <aessadik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:05:00 by aessadik          #+#    #+#             */
/*   Updated: 2024/05/06 19:20:58 by aessadik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "../lib/fractol.h"

int     keycheck(int keycode, t_fract *test)
{
    if (keycode == 53)
        exit(0);
    else if (keycode == 123)
        test->key_x -= 0.1;
	else if (keycode == 124)
        test->key_x += 0.1;
    else if (keycode == 126)
        test->key_y -= 0.1;
    else if (keycode == 125)
        test->key_y += 0.1;
	printf("test %f\n", test->key_x);
	return (0);
}
int c(void)
{
	exit(0);
	return 1;
}
void pixel_put(t_dat *data, int x, int y, int clr)
{
	char *s;
	
	s = data->addr + (y * data->line + x * (data->bpp / 8));
	*(unsigned int *)s = clr;
}
void window(char **av)
{
	t_mlx vars;
	t_dat img;
	t_fract *test = malloc(sizeof(t_fract));
	t_complex c1;
	vars.mlx = mlx_init();
	vars.mlx_w = mlx_new_window(vars.mlx, H, W, *av + 2);
	img.im = mlx_new_image(vars.mlx, W, H);
	img.addr = mlx_get_data_addr(img.im, &img.bpp, &img.line, &img.end);
	draw(vars ,&img, test);
	mlx_put_image_to_window(vars.mlx, vars.mlx_w, img.im, 0, 0);
	mlx_key_hook(vars.mlx_w, keycheck, test);
	// draw(vars ,&img, test);
	// mlx_put_image_to_window(vars.mlx, vars.mlx_w, img.im, 0, 0);
	mlx_hook(vars.mlx_w, 17, 0, c ,&vars);
	mlx_loop(vars.mlx);
   free(&vars);
}

int main(int ac , char **av)
{
	t_mlx var;
	window(av);
	
}


