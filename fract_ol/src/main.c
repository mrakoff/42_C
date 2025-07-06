/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalangi <msalangi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 14:40:52 by msalangi          #+#    #+#             */
/*   Updated: 2025/07/06 15:54:02 by msalangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

// 0.28 0.008
// -0.7269 0.1889
// -0.75 0.11
// 0.35 -0.35
// -0.74543 0.11301 - very cool

void	ft_init(t_fractal *fractal)
{
	fractal->mlx = mlx_init(SIZE, SIZE, "fractol", false);
	fractal->img = mlx_new_image(fractal->mlx, SIZE, SIZE);
	fractal->new_max = 2;
	fractal->new_min = -2;
	fractal->old_max = SIZE;
	fractal->old_min = 0;
}

int	main(int argc, char **argv)
{
	t_fractal	*fractal;

	fractal = malloc(sizeof(t_fractal));
	if (argc == 2 && (ft_strncmp(argv[1], "mandelbrot", 10) == 0))
		fractal->type = MANDELBROT;
	else if (argc == 4 && ft_strncmp(argv[1], "julia", 5) == 0)
	{
		fractal->type = JULIA;
		if (ft_check_julia(argv, fractal) != 0)
			return (free(fractal), write(2, &WRONG_ARG, sizeof(WRONG_ARG)), 1);
	}
	else
		return (free(fractal), write(2, &NO_ARG, sizeof(NO_ARG)), 1);
	ft_init(fractal);
	ft_render(fractal);
	if (mlx_image_to_window(fractal->mlx, fractal->img, 0, 0) < 0)
		return (1);
	mlx_scroll_hook(fractal->mlx, &ft_scroll, fractal);
	mlx_close_hook(fractal->mlx, ft_exit, fractal);
	mlx_key_hook(fractal->mlx, &ft_esc, fractal);
	mlx_loop(fractal->mlx);
	mlx_delete_image(fractal->mlx, fractal->img);
	mlx_terminate(fractal->mlx);
	return (free(fractal), 0);
}
