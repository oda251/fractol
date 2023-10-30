/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_fractals.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 19:22:01 by yoda              #+#    #+#             */
/*   Updated: 2023/10/30 22:07:42 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	choice_color(t_point *index, int n)
{
	if (n == ITER_MAX)
		index->color = 0x00000000;
	else
		index->color = 0x0000002F * n;
}

void	solve_mandel(t_point *index, t_img *img)
{
	int		i;
	t_cmp	c;
	t_cmp	z;

	c.real = (index->x - WIN_WIDTH / 2) / img->zoom;
	c.imag = (index->y - WIN_HEIGHT / 2) / img->zoom;
	z.imag = 0.0;
	z.real = 0.0;
	i = -1;
	while (++i < ITER_MAX)
	{
		z.imag = square_cmb(z).imag + c.imag;
		z.real = square_cmb(z).real + c.real;
		if (z.real * z.real + z.imag * z.imag > 4)
			break ;
	}
	choice_color(index, i);
}
