/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalangi <msalangi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 16:06:33 by msalangi          #+#    #+#             */
/*   Updated: 2025/07/06 06:20:28 by msalangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Z = Z^2 + C every iteration
// where Z starts at 0
// and C is a complex number that corresponds to 
// a point in the complex plane (= pixel location)
// every iteration a new pixel location is calculated to check
// squaring the thing and adding c = calculating new Z values
// inbound = the point is located within -2 and +2
*/

#include "../include/fractol.h"

int	ft_mandelbrot(t_complex c)
{
	t_complex	z;
	int			i;
	double		z_real;

	z.x_r = 0.0;
	z.y_i = 0.0;
	i = 0;
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
