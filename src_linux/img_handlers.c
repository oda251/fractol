/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_handlers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 04:46:26 by yoda              #+#    #+#             */
/*   Updated: 2023/11/07 09:29:17 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	reset_global_data(t_global_data *img)
{
	mlx_destroy_image(img->mlx, img->img);
	img->img = mlx_new_image(img->mlx, img->win_width, img->win_height);
	if (img->img == NULL)
	{
		mlx_destroy_window(img->mlx, img->win);
		perror("fractol: mlx_new_image");
		exit(EXIT_FAILURE);
	}
	img->buffer = mlx_get_data_addr(img->img, &img->pixel_bits,
			&img->line_bytes, &img->endian);
	img->zoom = img->win_height / 3;
	img->center_x = img->win_width / 2;
	img->center_y = img->win_height / 2;
}

void	shift_color_range(t_global_data *img)
{
	mlx_destroy_image(img->mlx, img->img);
	img->img = mlx_new_image(img->mlx, img->win_width, img->win_height);
	if (img->img == NULL)
	{
		mlx_destroy_window(img->mlx, img->win);
		perror("fractol: mlx_new_image");
		exit(EXIT_FAILURE);
	}
	img->buffer = mlx_get_data_addr(img->img, &img->pixel_bits,
			&img->line_bytes, &img->endian);
	if (img->color_range == DEFAULT_COLOR_RANGE)
		img->color_range = 0xFFFFFFFF / ITER_MAX;
	else if (img->color_range == 0xFFFFFFFF / ITER_MAX)
		img->color_range = 0xFF0000FF / ITER_MAX;
	else if (img->color_range == 0xFF0000FF / ITER_MAX)
		img->color_range = 0xFF00FF00 / ITER_MAX;
	else if (img->color_range == 0xFF00FF00 / ITER_MAX)
		img->color_range = 0xFFFF0000 / ITER_MAX;
	else
		img->color_range = DEFAULT_COLOR_RANGE;
	reset_global_data(img);
}

int	expose(t_global_data *img)
{
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
	return (1);
}
