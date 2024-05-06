/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessadik <aessadik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 09:40:51 by aessadik          #+#    #+#             */
/*   Updated: 2024/05/06 19:15:11 by aessadik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
#define FRACTOL_H


#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_complex{
    double real;
    double imag;
} t_complex;

typedef struct s_image{
    void *im;
    char *addr;
    int bpp;
    int line;
    int end;
} t_dat;
typedef struct s_fracts{
    double zx;
    double   zy;
    double  cy;
    double  cx;
    unsigned long colors;
    int iter;
    double key_x;
    double key_y;
}   t_fract;

typedef struct s_mlx{
    
    t_fract fracts;
    void *mlx;
    void *mlx_w;
    t_dat test;
    
}   t_mlx;

#define H 800
#define W 800

void init(void);
int coloring(int iter);
t_complex	calculate(t_complex z1);
double scale(double x, double oldMax, double newMin, double newMax);
int mandelbrot(t_complex c);
void pixel_put(t_dat *data, int x, int y, int clr);
void draw(t_mlx test ,t_dat *img, t_fract *test1);
int     keycheck(int keycode, t_fract *test);
void draw_j(t_dat *img);
#endif 

