/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 20:56:25 by yoda              #+#    #+#             */
/*   Updated: 2023/11/07 07:55:32 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	error_invalid_args(char *str)
{
	ft_puterror("fractol: invalid arguments: ");
	ft_puterror(str);
	ft_puterror("\n");
	ft_puterror("usage: ./fractol ");
	ft_puterror("[mandelbrot|julia|cubic|newton] [decimal] [decimal]\n");
	ft_puterror("to operate:\n");
	ft_puterror("  - move: W, A, S, D or arrow keys\n");
	ft_puterror("  - zoom: mouse wheel or left/right click\n");
	ft_puterror("  - change fractal: Q or E\n");
	exit(EXIT_FAILURE);
}
