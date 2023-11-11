/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:34:08 by yoda              #+#    #+#             */
/*   Updated: 2023/11/11 18:01:09 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_global_data			img;

	if (argc == 1)
		error_invalid_args("too few");
	init_global_data(&img, argc - 1, argv + 1);
	render_fractal(&img);
	mlx_expose_hook(img.win, expose, &img);
	mlx_hook(img.win, EVENT_CLOSE_BTN, (1L<<2), close_window, &img);
	mlx_mouse_hook(img.win, mouse_hook, &img);
	mlx_key_hook(img.win, key_hook, &img);
	mlx_loop(img.mlx);
	return (0);
}

static void	get_params(t_global_data *img, int argc, char **argv)
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

void	init_global_data(t_global_data *img, int argc, char **argv)
{
	img->win_height = WIN_HEIGHT;
	img->win_width = WIN_WIDTH;
	img->zoom = WIN_WIDTH / 4.0;
	img->offset_x = -2;
	img->offset_y = -1.5;
	img->fractal = trans_fractal(argv[0]);
	if ((img->fractal != julia && argc >= 2)
		|| (img->fractal == julia && argc > 3))
		error_invalid_args("too many");
	img->color_range = DEFAULT_COLOR_RANGE;
	get_params(img, argc - 1, argv + 1);
	img->mlx = mlx_init();
	if (img->mlx == NULL)
		perror_exit("fractol: mlx_init");
	img->win = mlx_new_window(img->mlx, WIN_WIDTH, WIN_HEIGHT, WIN_TITLE);
	if (img->win == NULL)
		perror_exit("fractol: mlx_new_window");
	img->img = mlx_new_image(img->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (img->img == NULL)
		perror_exit("fractol: mlx_new_image");
	img->buffer = mlx_get_data_addr(img->img, &img->pixel_bits,
			&img->line_bytes, &img->endian);
}

// __attribute__((destructor))
// static void destructor() {
//     system("leaks -q fractol");
// }
