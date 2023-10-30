/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 18:48:51 by yoda              #+#    #+#             */
/*   Updated: 2023/10/30 19:18:29 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_cmp	square_cmb(t_cmp a)
{
	t_cmp	b;

	b.real = a.real * a.real - a.imag * a.imag;
	b.imag = 2 * a.real * a.imag;
	return (b);
}

int	solve_mandel(t_point index)
{
	int		i;
	t_cmp	c;
	t_cmp	z;

	c.real = (index.x - 250) / 100.0;
	c.imag = (index.y - 250) / 100.0;
	z.imag = 0.0;
	z.real = 0.0;
	i = -1;
	while (++i < ITER_MAX)
	{
		z.imag = square_cmb(z).imag + c.imag;
		z.real = square_cmb(z).real + c.real;
		if (z.real * z.real + z.imag * z.imag > 4)
			break ;
	}
	return (i);
}

int	main(int c, char **v)
{
	(void) c;
	(void) v;
	void	*mlx = mlx_init();
	// 窓の作成
	void	*win = mlx_new_window(mlx, 500, 500, "Fractol");
	void	*img = mlx_new_image(mlx, 500, 500);
	// １ピクセルあたりのビット数
	int		pixel_bits;
	// １ラインあたりのバイト数
	int		line_bytes;
	// エンディアン データを下位、上位バイトどちらから読み込むか
	int		endian;
	char	*buffer = mlx_get_data_addr(img, &pixel_bits, &line_bytes, &endian);

	int	color = 0x0000FF00;
	int	green = 0x0000FF00;
	int	red = 0x00FF0000;
	if (pixel_bits != 32)
	// 32ビットカラーでない場合に合わせるのかな？
	{
		red = mlx_get_color_value(mlx, red);
		green = mlx_get_color_value(mlx, green);
	}
	int x = -1;
	while (++x < 500)
	{
		int y = -1;
		while (++y < 500)
		{
			t_point index;
			int pixel = (y * line_bytes) + (x * 4);

			index.x = x;
			index.y = y;
			int n = solve_mandel(index);
			if (n < 100)
			{
				color = red;
			}
			else if (n == 100)
				color = green;

			if (endian == 1)        // Most significant (Alpha) byte first
			{
				buffer[pixel + 0] = (color >> 24);
				buffer[pixel + 1] = (color >> 16) & 0xFF;
				buffer[pixel + 2] = (color >> 8) & 0xFF;
				buffer[pixel + 3] = (color) & 0xFF;
			}
			else if (endian == 0)   // Least significant (Blue) byte first
			{
				buffer[pixel + 0] = (color) & 0xFF;
				buffer[pixel + 1] = (color >> 8) & 0xFF;
				buffer[pixel + 2] = (color >> 16) & 0xFF;
				buffer[pixel + 3] = (color >> 24);
			}
		}
	}
	mlx_put_image_to_window(mlx, win, img, 0, 0);
	mlx_loop(mlx);
}
