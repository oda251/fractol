/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 21:55:53 by yoda              #+#    #+#             */
/*   Updated: 2023/11/07 09:03:25 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse_hook(int button, int x, int y, t_global_data *img)
{
	if ((button == MOUSE_WHEEL_UP || button == MOUSE_WHEEL_DOWN
			|| button == MOUSE_BTN_L || button == MOUSE_BTN_R)
		&& x >= 0 && x <= WIN_WIDTH && y >= 0 && y <= WIN_HEIGHT)
	{
		if (button == MOUSE_BTN_L || button == MOUSE_WHEEL_UP)
			img->zoom *= 1.1;
		else if (button == MOUSE_BTN_R || button == MOUSE_WHEEL_DOWN)
			img->zoom /= 1.1;
		img->center_x += (img->win_width / 2.0 - x);
		img->center_y += (img->win_height / 2.0 - y);
		render_fractal(img);
	}
	return (1);
}

static int	switch_fractal(int current, int keycode, t_global_data *img)
{
	int	next;

	reset_global_data(img);
	if (keycode == KEY_Q)
		next = current - 1;
	else
		next = current + 1;
	while (next < 0)
		next = AVAILABLE_FRACTALS + next;
	if (next >= AVAILABLE_FRACTALS)
		next %= AVAILABLE_FRACTALS;
	return (next);
}

int	key_hook(int keycode, t_global_data *img)
{
	if (keycode == KEY_ESC)
		close_window(img);
	else if (keycode == KEY_W || keycode == KEY_UP)
		img->center_y += 10;
	else if (keycode == KEY_A || keycode == KEY_LEFT)
		img->center_x += 10;
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		img->center_y -= 10;
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		img->center_x -= 10;
	else if (keycode == KEY_Q || keycode == KEY_E)
		img->fractal = switch_fractal(img->fractal, keycode, img);
	else if (keycode == KEY_PLUS)
		img->zoom *= 1.1;
	else if (keycode == KEY_MINUS)
		img->zoom /= 1.1;
	else if (keycode == KEY_SPACE)
		shift_color_range(img);
	else
		return (1);
	render_fractal(img);
	return (1);
}
