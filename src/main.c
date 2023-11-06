/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:34:08 by yoda              #+#    #+#             */
/*   Updated: 2023/11/07 07:57:55 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_img			img;

	if (argc == 1)
		error_invalid_args("too few");
	init_img(&img, argc - 1, argv + 1);
	render_fractal(&img);
	mlx_hook(img.win, EVENT_CLOSE_BTN, 0, close_window, &img);
	mlx_mouse_hook(img.win, mouse_hook, &img);
	mlx_key_hook(img.win, key_hook, &img);
	mlx_loop(img.mlx);
	return (0);
}
