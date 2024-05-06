/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessadik <aessadik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:55:34 by aessadik          #+#    #+#             */
/*   Updated: 2024/05/05 23:54:11 by aessadik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/fractol.h"


int coloring(int iterations) {
    int dark_blue = 0x000033; 
    int sky_blue = 0x6699FF;


    float t = (float)iterations / 255.0;
    int r = (1 - t) * ((dark_blue >> 16) & 0xFF) + t * ((sky_blue >> 16) & 0xFF);
    int g = (1 - t) * ((dark_blue >> 8) & 0xFF) + t * ((sky_blue >> 8) & 0xFF);
    int b = (1 - t) * (dark_blue & 0xFF) + t * (sky_blue & 0xFF);

    return (r << 16) | (g << 8) | b;
}
 //+ (green << 8) + blue
double scale(double x, double oldMax, double newMin, double newMax) {
    return newMin + (newMax - newMin) * (x) / (oldMax);
}
  