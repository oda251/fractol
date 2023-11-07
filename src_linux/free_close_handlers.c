/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_close_handlers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 04:11:10 by yoda              #+#    #+#             */
/*   Updated: 2023/11/07 13:35:48 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	free_img(t_global_data *img)
{
	if (!img)
		return ;
	if (img->img)
		mlx_destroy_image(img->mlx, img->img);
	if (img->win)
		mlx_destroy_window(img->mlx, img->win);
	if (img->mlx)
	{
		mlx_loop_end(img->mlx);
		mlx_destroy_display(img->mlx);
		free(img->mlx);
	}
}

int	close_window(t_global_data *img)
{
	free_img(img);
	exit(EXIT_SUCCESS);
}
