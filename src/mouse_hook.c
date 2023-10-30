/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 21:55:53 by yoda              #+#    #+#             */
/*   Updated: 2023/10/30 22:04:38 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse_hook(int button, int x, int y, t_img *img)
{
	if (1 <= button && button <= 5 && button != 3
		&& x >= 0 && x <= WIN_WIDTH && y >= 0 && y <= WIN_HEIGHT)
	{
		if (button == 4 || button == 1)
			img->zoom *= 1.1;
		else if (button == 5 || button == 2)
			img->zoom /= 1.1;
		render_fractal(img);
	}
	return (1);
}
