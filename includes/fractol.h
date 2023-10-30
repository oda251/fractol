/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 16:21:30 by yoda              #+#    #+#             */
/*   Updated: 2023/10/30 22:22:06 by yoda             ###   ########.fr       */
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
# define ITER_MAX 100
# define WIN_WIDTH 640
# define WIN_HEIGHT 480
# define WIN_TITLE "Fractol"

enum	e_fractal{
	mandel,
	julia,
	phoenix,
	barnsley,
	flame
};
typedef struct s_cmp
{
	double	real;
	double	imag;
}	t_cmp;
typedef struct s_point
{
	int	x;
	int	y;
	int	color;
}	t_point;
typedef struct s_img
{
	void			*mlx;
	void			*img;
	void			*win;
	char			*buffer;
	int				pixel_bits;
	int				line_bytes;
	int				endian;
	enum e_fractal	fractal;
	double			zoom;
}	t_img;

t_cmp	square_cmb(t_cmp a);
void	render_fractal(t_img *img);
void	solve_mandel(t_point *index, t_img *img);
int		args_error_exit(void);
int		mouse_hook(int button, int x, int y, t_img *img);

#endif
