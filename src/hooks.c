/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 21:55:53 by yoda              #+#    #+#             */
/*   Updated: 2023/11/11 17:56:05 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	abs_d(double n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int	mouse_hook(int button, int x, int y, t_global_data *img)
{
	double	scaling;

	scaling = 1.0;
	if ((button == MOUSE_WHEEL_UP || button == MOUSE_WHEEL_DOWN
			|| button == MOUSE_BTN_L || button == MOUSE_BTN_R)
		&& x >= 0 && x <= WIN_WIDTH && y >= 0 && y <= WIN_HEIGHT)
	{
		if (button == MOUSE_BTN_L || button == MOUSE_WHEEL_UP)
			scaling *= 1.1;
		else if (button == MOUSE_BTN_R || button == MOUSE_WHEEL_DOWN)
			scaling /= 1.1;
		img->zoom *= scaling;
		img->offset_x += (scaling - 1) * x / img->zoom;
		img->offset_y += (scaling - 1) * y / img->zoom;
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
		img->offset_y -= 10 / img->zoom;
	else if (keycode == KEY_A || keycode == KEY_LEFT)
		img->offset_x -= 10 / img->zoom;
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		img->offset_y += 10 / img->zoom;
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		img->offset_x += 10 / img->zoom;
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
