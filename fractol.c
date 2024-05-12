/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessadik <aessadik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 01:36:01 by aessadik          #+#    #+#             */
/*   Updated: 2024/05/12 16:44:29 by aessadik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/fractol.h"

void run(char **av)
{
    t_mlx var;
	double dbl;
	double dbl_;
	var.fracts.x_max = 2;
	var.fracts.x_min = -2;
	var.fracts.y_max = 2;
	var.fracts.y_min = -2;
	if(!ft_strcmp(av[1], "mandelbrot"))
		window_m(&var, av);
	if(!ft_strcmp(av[1], "julia"))
	{
		if (!ft_atof(av[2], &dbl) || !ft_atof(av[3], &dbl_))
		{
			printf("ERROR\n");
			exit(-1); 
		}
		window_j(&var, av, dbl, dbl_);
	}
}
int main(int ac, char **av)
{
	t_mlx var;
	var.fracts.x_max = 2;
	var.fracts.x_min = -2;
	var.fracts.y_max = 2;
	var.fracts.y_min = -2;
	if(ac == 2 && !ft_strcmp(av[1], "mandelbrot"))
		window_m(&var, av);
	if(ac == 4 && !ft_strcmp(av[1], "julia"))
	{
		if (!ft_atof(av[2], &var.c_real) || !ft_atof(av[3], &var.c_imag))
		{
			printf("ERROR\n");
			exit(-1); 
		}
		window_j(&var, av, var.c_real, var.c_imag);
	}
}