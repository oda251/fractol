/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_fractals.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 19:22:01 by yoda              #+#    #+#             */
/*   Updated: 2023/11/07 07:57:00 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	choice_color(t_point *index, int n, int color_range)
{
	if (n == ITER_MAX)
		index->color = 0x00000000;
	else
		index->color = color_range * n;
}

void	solve_mandel(t_point *index, t_img *img)
{
	int		i;
	t_cmp	c;
	t_cmp	z;

	c.real = (index->x - img->center_x) / img->zoom;
	c.imag = (index->y - img->center_y) / img->zoom;
	z.imag = 0.0;
	z.real = 0.0;
	i = -1;
	while (++i < ITER_MAX)
	{
		if (z.real * z.real + z.imag * z.imag > 4)
			break ;
		z = square_cmp(z);
		z = plus_cmp(z, c);
	}
	choice_color(index, i, img->color_range);
}

void	solve_julia(t_point *index, t_img *img)
{
	int		i;
	t_cmp	c;
	t_cmp	z;

	c.real = img->julia_c.real;
	c.imag = img->julia_c.imag;
	z.real = (index->x - img->center_x) / img->zoom;
	z.imag = (index->y - img->center_y) / img->zoom;
	i = -1;
	while (++i < ITER_MAX)
	{
		if (z.real * z.real + z.imag * z.imag > 4)
			break ;
		z = square_cmp(z);
		z = plus_cmp(z, c);
	}
	choice_color(index, i, img->color_range);
}

void	solve_cubic(t_point *index, t_img *img)
{
	int		i;
	t_cmp	c;
	t_cmp	z;

	c.real = (index->x - img->center_x) / img->zoom;
	c.imag = (index->y - img->center_y) / img->zoom;
	z.imag = 0.0;
	z.real = 0.0;
	i = -1;
	while (++i < ITER_MAX)
	{
		if (z.real * z.real + z.imag * z.imag > 4)
			break ;
		z = cube_cmp(z);
		z = plus_cmp(z, c);
	}
	choice_color(index, i, img->color_range);
}

void	solve_newton(t_point *index, t_img *img)
{
	int		i;
	t_cmp	z;
	t_cmp	tmp;

	z.real = (index->x - img->center_x) / img->zoom;
	z.imag = (index->y - img->center_y) / img->zoom;
	i = -1;
	while (++i < ITER_MAX)
	{
		tmp = minus_cmp(z, real_to_cmp(1));
		if (tmp.real * tmp.real + tmp.imag * tmp.imag < pow(1e-6, 2))
			break ;
		z = minus_cmp(z,
				devide_cmp(minus_cmp(cube_cmp(z), real_to_cmp(1)),
					multiple_cmp(square_cmp(z), real_to_cmp(3))));
	}
	choice_color(index, i, img->color_range);
}
