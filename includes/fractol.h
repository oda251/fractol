/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 16:21:30 by yoda              #+#    #+#             */
/*   Updated: 2023/11/19 15:22:02 by yoda             ###   ########.fr       */
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
# include <stdbool.h>
# include "mlx.h"
# include "key_macros.h"
# include "libft.h"
# ifndef ITER_MAX
#  define ITER_MAX 60
# endif
# define WIN_WIDTH 640
# define WIN_HEIGHT 480
# define WIN_TITLE "Fractol"
# define AVAILABLE_FRACTALS 3
# define DEFAULT_COLOR_RANGE 0x00080EEF

enum	e_fractal{
	mandel,
	julia,
	cubic,
	newton,
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
typedef struct s_global_data
{
	void			*mlx;
	void			*img;
	void			*win;
	char			*buffer;
	int				pixel_bits;
	int				line_bytes;
	int				endian;
	int				color_range;
	enum e_fractal	fractal;
	double			offset_x;
	double			offset_y;
	t_cmp			julia_c;
	double			zoom;
	int				win_width;
	int				win_height;
}	t_global_data;

int		mouse_hook(int button, int x, int y, t_global_data *img);
void	free_img(t_global_data *img);
int		close_window(t_global_data *img);
int		key_hook(int keycode, t_global_data *img);
void	init_global_data(t_global_data *img, int argc, char **argv);
void	reset_global_data(t_global_data *img);
void	shift_color_range(t_global_data *img);
void	render_fractal(t_global_data *img);
t_cmp	square_cmp(t_cmp a);
t_cmp	multiple_cmp(t_cmp a, t_cmp b);
t_cmp	cube_cmp(t_cmp a);
t_cmp	plus_cmp(t_cmp a, t_cmp b);
t_cmp	minus_cmp(t_cmp a, t_cmp b);
t_cmp	devide_cmp(t_cmp a, t_cmp b);
t_cmp	real_to_cmp(double real);
void	solve_mandel(t_point *index, t_global_data *img);
void	solve_julia(t_point *index, t_global_data *img);
void	solve_cubic(t_point *index, t_global_data *img);
void	solve_newton(t_point *index, t_global_data *img);
void	error_invalid_args(char *str);
void	perror_exit(char *str);
int		expose(t_global_data *img);

#endif
