/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 19:30:00 by yoda              #+#    #+#             */
/*   Updated: 2023/10/30 22:22:20 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	drow_pixel(char *buffer, int pixel, int color, int endian)
{
	if (endian == 1)
	{
		buffer[pixel + 0] = (color >> 24);
		buffer[pixel + 1] = (color >> 16) & 0xFF;
		buffer[pixel + 2] = (color >> 8) & 0xFF;
		buffer[pixel + 3] = (color) & 0xFF;
	}
	else if (endian == 0)
	{
		buffer[pixel + 0] = (color) & 0xFF;
		buffer[pixel + 1] = (color >> 8) & 0xFF;
		buffer[pixel + 2] = (color >> 16) & 0xFF;
		buffer[pixel + 3] = (color >> 24);
	}
}

void	render_fractal(t_img *img)
{
	t_point	index;
	int		pixel;

	index.x = -1;
	while (++(index.x) < WIN_WIDTH)
	{
		index.y = -1;
		while (++(index.y) < WIN_HEIGHT)
		{
			pixel = (index.y * img->line_bytes) + (index.x * 4);
			if (img->fractal == mandel)
				solve_mandel(&index, img);
			drow_pixel(img->buffer, pixel, index.color, img->endian);
		}
	}
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
}
