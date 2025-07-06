/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalangi <msalangi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 16:06:40 by msalangi          #+#    #+#             */
/*   Updated: 2025/07/06 06:40:47 by msalangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static double	ft_atof_fraction(char *str)
{
	double	fraction;
	double	dec;

	fraction = 0.0;
	dec = 1;
	if (*str == '.')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		fraction = fraction * 10 + (*str - '0');
		dec = dec * 10;
		str++;
	}
	return (fraction / dec);
}

static double	ft_atof(char *str)
{
	double	num;
	double	sign;
	double	fraction;

	num = 0.0;
	sign = 1.0;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -sign;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + (*str - '0');
		str++;
	}
	fraction = ft_atof_fraction(str);
	num = num + fraction;
	return (sign * num);
}

int	ft_check_julia(char **argv, t_fractal *fractal)
{
	int			ind;
	static int	i;

	ind = 2;
	while (ind < 4)
	{
		if (argv[ind][i] == '-' || argv[ind][i] == '+')
			i++;
		while (argv[ind][i] >= '0' && argv[ind][i] <= '9')
			i++;
		if (argv[ind][i] == '.')
			i++;
		while (argv[ind][i] >= '0' && argv[ind][i] <= '9')
			i++;
		if (argv[ind][i] != '\0')
			return (-1);
		else
		{
			ind++;
			i = 0;
		}
	}
	fractal->julia_x = ft_atof(argv[2]);
	fractal->julia_y = ft_atof(argv[3]);
	return (0);
}

int	ft_julia(t_fractal *fractal, t_complex c)
{
	t_complex	z;
	int			i;
	double		z_real;

	z.x_r = c.x_r;
	z.y_i = c.y_i;
	i = 0;
	c.x_r = fractal->julia_x;
	c.y_i = fractal->julia_y;
	while (i < MAX_ITERATIONS)
	{
		z_real = z.x_r * z.x_r - z.y_i * z.y_i + c.x_r;
		z.y_i = 2 * z.x_r * z.y_i + c.y_i;
		z.x_r = z_real;
		if (z.x_r * z.x_r + z.y_i * z.y_i >= 4)
			break ;
		i++;
	}
	return (i);
}
