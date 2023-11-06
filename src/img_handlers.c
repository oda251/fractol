/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_handlers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 04:46:26 by yoda              #+#    #+#             */
/*   Updated: 2023/11/07 07:53:02 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	get_params(t_img *img, int argc, char **argv)
{
	img->julia_c.real = -0.2;
	img->julia_c.imag = 0.7;
	if (argc >= 1)
	{
		if (is_decimal(argv[0]) == false)
			error_invalid_args(argv[0]);
		img->julia_c.real = ft_atod(argv[0]);
	}
	else
		return ;
	if (argc >= 2)
	{
		if (is_decimal(argv[1]) == false)
			error_invalid_args(argv[1]);
		img->julia_c.imag = ft_atod(argv[1]);
	}
}

static enum e_fractal	trans_fractal(char *str)
{
	if (ft_strcmp(str, "mandelbrot") == 0)
		return (mandel);
	else if (ft_strcmp(str, "julia") == 0)
		return (julia);
	else if (ft_strcmp(str, "cubic") == 0)
		return (cubic);
	else if (ft_strcmp(str, "newton") == 0)
		return (newton);
	else
		error_invalid_args(str);
	return (0);
}

void	init_img(t_img *img, int argc, char **argv)
{
	img->win_height = WIN_HEIGHT;
	img->win_width = WIN_WIDTH;
	img->zoom = WIN_HEIGHT / 3;
	img->center_x = WIN_WIDTH / 2;
	img->center_y = WIN_HEIGHT / 2;
	img->fractal = trans_fractal(argv[0]);
	img->color_range = DEFAULT_COLOR_RANGE;
	get_params(img, argc - 1, argv + 1);
	img->mlx = mlx_init();
	img->win = mlx_new_window(img->mlx, WIN_WIDTH, WIN_HEIGHT, WIN_TITLE);
	if (img->win == NULL)
	{
		perror("fractol: mlx_new_window");
		exit(EXIT_FAILURE);
	}
	img->img = mlx_new_image(img->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (img->img == NULL)
	{
		mlx_destroy_window(img->mlx, img->win);
		perror("fractol: mlx_new_image");
		exit(EXIT_FAILURE);
	}
	img->buffer = mlx_get_data_addr(img->img, &img->pixel_bits,
			&img->line_bytes, &img->endian);
}

void	reset_img(t_img *img)
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

void	shift_color_range(t_img *img)
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
	reset_img(img);
}

// int	resize_window(t_img *img, int new_width, int new_height)
// {
// 	mlx_destroy_image(img->mlx, img->img);
// 	img->win_width = new_width;
// 	img->win_height = new_height;
// 	img->img = mlx_new_image(img->mlx, img->win_width, img->win_height);
// 	img->buffer = mlx_get_data_addr(img->img, &img->pixel_bits,
// 			&img->line_bytes, &img->endian);
// 	reset_img(img);
// 	render_fractal(img);
// 	return (1);
// }
