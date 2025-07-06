/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalangi <msalangi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 05:25:25 by msalangi          #+#    #+#             */
/*   Updated: 2025/07/06 15:30:04 by msalangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	ft_scroll(double xdelta, double ydelta, void *fr)
{
	t_fractal	*fractal;

	xdelta = 0;
	fractal = fr;
	if (ydelta > 0)
	{
		fractal->new_max = (fractal->new_max) * 1.05;
		fractal->new_min = (fractal->new_min) * 1.05;
	}
	else if (ydelta < 0)
	{
		fractal->new_max = (fractal->new_max) * 0.95;
		fractal->new_min = (fractal->new_min) * 0.95;
	}
	ft_render(fractal);
}

void	ft_esc(mlx_key_data_t keydata, void *fr)
{
	t_fractal	*fractal;

	fractal = fr;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		mlx_delete_image(fractal->mlx, fractal->img);
		mlx_terminate(fractal->mlx);
		free(fractal);
		exit(EXIT_SUCCESS);
	}
}

void	ft_exit(void *fr)
{
	t_fractal	*fractal;

	fractal = fr;
	mlx_delete_image(fractal->mlx, fractal->img);
	mlx_terminate(fractal->mlx);
	free(fractal);
	exit(EXIT_SUCCESS);
}
