/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:34:08 by yoda              #+#    #+#             */
/*   Updated: 2023/10/30 22:22:36 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

enum e_fractal	trans_fractal(char *str);
void			sset_img(t_img *img);

int	main(int c, char **v)
{
	t_img			img;

	if (c == 1)
		img.fractal = mandel;
	else if (c == 2)
		img.fractal = trans_fractal(v[1]);
	else
		args_error_exit();
	sset_img(&img);
	render_fractal(&img);
	mlx_mouse_hook(img.win, mouse_hook, &img);
	mlx_loop(img.mlx);
	return (0);
}

enum e_fractal	trans_fractal(char *str)
{
	if (ft_strcmp(str, "mandel") == 0)
		return (mandel);
	else if (ft_strcmp(str, "julia") == 0)
		return (julia);
	else if (ft_strcmp(str, "phoenix") == 0)
		return (phoenix);
	else if (ft_strcmp(str, "barnsley") == 0)
		return (barnsley);
	else if (ft_strcmp(str, "flame") == 0)
		return (flame);
	else
		args_error_exit();
	return (0);
}

void	sset_img(t_img *img)
{
	img->mlx = mlx_init();
	img->win = mlx_new_window(img->mlx, WIN_WIDTH, WIN_HEIGHT, WIN_TITLE);
	img->img = mlx_new_image(img->mlx, WIN_WIDTH, WIN_HEIGHT);
	img->buffer = mlx_get_data_addr(img->img, &img->pixel_bits,
			&img->line_bytes, &img->endian);
	img->zoom = 100.0;
}
