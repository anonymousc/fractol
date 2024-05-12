/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessadik <aessadik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 21:50:05 by aessadik          #+#    #+#             */
/*   Updated: 2024/05/12 20:07:45 by aessadik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/fractol.h"

double	scale(double x, double oldMax, double newMin, double newMax)
{
	return (newMin + (newMax - newMin) * (x) / (oldMax));
}

int	julia(t_complex *z, double real, double imagin)
{
	t_complex	c;
	t_fract		fracts;
	int			i;
	double		tmp;

	c.real = real;
	c.imag = imagin;
	i = 0;
	fracts.iter = 100;
	while (i < fracts.iter)
	{
		tmp = z->real * z->real - z->imag * z->imag + c.real;
		z->imag = 2 * z->real * z->imag + c.imag;
		z->real = tmp;
		if ((z->real * z->real + z->imag * z->imag) > 4)
		{
			return (coloring(i));
		}
		i++;
	}
	return (0);
}

int	mandelbrot(t_complex c)
{
	t_fract		fracts;
	t_complex	z;
	int			i;
	double		tmp;

	z.imag = 0;
	z.real = 0;
	i = 0;
	fracts.iter = 100;
	while (i < fracts.iter)
	{
		tmp = z.real * z.real - z.imag * z.imag + c.real;
		z.imag = 2 * z.real * z.imag + c.imag;
		z.real = tmp;
		if ((z.real * z.real + z.imag * z.imag) > 4)
			return (coloring(i));
		i++;
	}
	return (0);
}
