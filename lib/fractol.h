/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessadik <aessadik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 09:40:51 by aessadik          #+#    #+#             */
/*   Updated: 2024/05/12 21:00:05 by aessadik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_complex
{
	double			real;
	double			imag;
}					t_complex;

typedef struct s_image
{
	void			*im;
	char			*addr;
	int				bpp;
	int				line;
	int				end;
}					t_dat;
typedef struct s_fracts
{
	double			zx;
	double			zy;
	double			cy;
	double			cx;
	double			x_max;
	double			x_min;
	double			y_max;
	double			y_min;
	unsigned long	colors;
	int				iter;
	double			key_x;
	double			key_y;
}					t_fract;

typedef struct s_mlx
{
	t_fract			fracts;
	void			*mlx;
	void			*mlx_w;
	t_dat			test;
	double			c_real;
	double			c_imag;

}					t_mlx;

# define H 800
# define W 800

int					coloring(int iter);
t_complex			calculate(t_complex z1);
double				scale(double x, double oldMax, double newMin,
						double newMax);
int					mandelbrot(t_complex c);
int					julia(t_complex *z, double real, double imagin);
void				pixel_put(t_mlx *data, int x, int y, int clr);
void				draw_m(t_mlx *test1);
int					keycheck(int keycode, t_mlx *test);
void				draw_j(t_mlx *test1, double real, double imagine);
void				window_j(t_mlx *vars, char **av, double real,
						double imagine);
void				window_m(t_mlx *vars, char **av);
int					mouse(int keycode, int x, int y, t_mlx *test);
void				render_fracts(t_mlx *test);
double				get_x_value(double x_max, double x_min);
double				get_y_value(double y_max, double y_min);
int					c(void);
int					ft_strcmp(char *s1, char *s2);
void				render_fracts_j(t_mlx *test);
int					mousej(int keycode, int x, int y, t_mlx *test);
int					keycheckj(int keycode, t_mlx *test);
int					ft_atof(const char *s, double *arg);

#endif