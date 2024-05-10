/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessadik <aessadik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 01:36:01 by aessadik          #+#    #+#             */
/*   Updated: 2024/05/10 22:45:08 by aessadik         ###   ########.fr       */
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
	if(ac == 2)
      run(av);
	if(ac == 4)
	{
		if(ac == 2)
		{
			exit(1);
		}
		run(av);
	}
}