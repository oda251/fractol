/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 20:56:25 by yoda              #+#    #+#             */
/*   Updated: 2023/10/30 20:56:32 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	args_error_exit(void)
{
	ft_puterror("Usage: ./fractol [fractal]\n");
	exit(0);
}