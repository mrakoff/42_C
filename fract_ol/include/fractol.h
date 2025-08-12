/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalangi <msalangi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 14:29:14 by mel               #+#    #+#             */
/*   Updated: 2025/07/18 19:28:09 by msalangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

# define SIZE			800
# define MAX_ITERATIONS	1500

# define BLACK			0x000000ff

# define MANDELBROT		1
# define JULIA			2

# define NO_ARG	"\nValid options:\n\n  mandelbrot\n  julia <arg 1> <arg 2>\n\n"
# define WRONG_ARG	"\nWrong format, try julia <arg 1> <arg 2>\n\n"

// struct for complex numbers
typedef struct s_complex
{
	double	x_r;
	double	y_i;
}	t_complex;

// struct for a color
typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

// everything related to fractal
typedef struct s_fractal
{
	int				type;		// - name of the fractal
	double			julia_x;	// - used for julia
	double			julia_y;	// - used for julia
	double			new_max;	// - values for scaling
	double			new_min;
	double			old_min;
	double			old_max;
	mlx_image_t		*img;		// - image pointer
	mlx_t			*mlx;		// - connection pointer
}	t_fractal;

// MANDELBROT.C
int		ft_mandelbrot(t_complex c);

// JULIA.C
int		ft_julia(t_fractal *fractal, t_complex c);
int		ft_check_julia(char **argv, t_fractal *fractal);

// RENDER.C
void	ft_render(t_fractal *fractal);

// HOOKS.C
void	ft_scroll(double xdelta, double ydelta, void *fr);
void	ft_esc(mlx_key_data_t keydata, void *fr);
void	ft_exit(void *fr);

#endif