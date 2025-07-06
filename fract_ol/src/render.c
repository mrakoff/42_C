/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalangi <msalangi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 20:19:17 by msalangi          #+#    #+#             */
/*   Updated: 2025/07/06 15:30:51 by msalangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

/* 800 x 800 window, values should be scaled down - ft_pxl_to_c()
// if x + y(i) is diverging to infinity - not a part of fractal
// if x + y(i) is limited - part of fractal

//							|
//							|
//							| 2i	  * <- (2, 2i)
//							|
//							|
// x (real) ----------------0----1----2-------->
// 							|
//							|
//							|
//							|
//							|
//					y (imaginary)
*/

uint32_t	ft_color(int depth)
{
	t_color	color;

	if (depth >= MAX_ITERATIONS)
		return (BLACK);
	else if (depth <= 1)
		return (BLACK);
	color.r = 0;
	color.g = (depth * 20) % 255;
	color.b = (depth * 250) % 255;
	return ((color.r << 16 | color.g << 8 | color.b));
}

t_complex	ft_pxl_to_c(t_fractal *fractal, int x, int y)
{
	t_complex	c;

	c.x_r = (double)(fractal->new_max - fractal->new_min)
		* (x - fractal->old_min) / (fractal->old_max - fractal->old_min)
		+ fractal->new_min;
	c.y_i = (double)(fractal->new_min - fractal->new_max)
		* (y - fractal->old_min) / (fractal->old_max - fractal->old_min)
		+ fractal->new_max;
	return (c);
}

void	ft_render(t_fractal *fractal)
{
	double		x;
	double		y;
	t_complex	c;
	int			depth;

	x = 0;
	while (x < SIZE)
	{
		y = 0;
		while (y < SIZE)
		{
			c = ft_pxl_to_c(fractal, x, y);
			if (fractal->type == MANDELBROT)
				depth = ft_mandelbrot(c);
			else
				depth = ft_julia(fractal, c);
			mlx_put_pixel(fractal->img, x, y, ft_color(depth));
			y++;
		}
		x++;
	}
	mlx_image_to_window(fractal->mlx, fractal->img, 0, 0);
}

//0x201585ff
// 0x899bccff
//1d13d4

	// if (depth > MAX_ITERATIONS * 0.99 && depth < MAX_ITERATIONS)
	// 	return (0x453bf7ff);

	// else if (depth == MAX_ITERATIONS && fractal->type == MANDELBROT)
	// 	mlx_put_pixel(fractal->img, x, y, 0x000000ff);
	// else if (fractal->type == MANDELBROT)
	// else if (depth == MAX_ITERATIONS && fractal->type == JULIA)
	// 	mlx_put_pixel(fractal->img, x, y, BLUE);
	// else if (depth > MAX_ITERATIONS / 10 && fractal->type == JULIA)
	// 	mlx_put_pixel(fractal->img, x, y, BLUE + (depth % 255) * 2);
	// else
	// 	mlx_put_pixel(fractal->img, x, y, 0x000000ff);