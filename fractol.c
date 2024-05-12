/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessadik <aessadik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 01:36:01 by aessadik          #+#    #+#             */
/*   Updated: 2024/05/12 21:08:18 by aessadik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/fractol.h"

int	main(int ac, char **av)
{
	t_mlx	var;

	var.fracts.x_max = 2;
	var.fracts.x_min = -2;
	var.fracts.y_max = 2;
	var.fracts.y_min = -2;
	if (ac == 2 && !ft_strcmp(av[1], "mandelbrot"))
		window_m(&var, av);
	if (ac == 4 && !ft_strcmp(av[1], "julia"))
	{
		if (!ft_atof(av[2], &var.c_real) || !ft_atof(av[3], &var.c_imag))
		{
			write(2, "\033[31mMissing args or Invalid args\n", 36);
			exit(1);
		}
		window_j(&var, av, var.c_real, var.c_imag);
	}
	else
	{
		write(2, "\033[31musage ./fractol julia or mandelbrot ", 41);
		write(2, "for julia give its real imaginary\n", 35);
		exit(1);
	}
}
