/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 16:21:30 by yoda              #+#    #+#             */
/*   Updated: 2023/10/29 21:42:22 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <limits.h>
# include <fcntl.h>
# include <OpenGL/gl.h>
# include "mlx.h"
# include "libft.h"

typedef struct s_cmp
{
	double	real;
	double	imag;
}	t_cmp;
typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

#endif
