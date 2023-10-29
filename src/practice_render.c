/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 18:48:51 by yoda              #+#    #+#             */
/*   Updated: 2023/10/29 21:19:59 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
	int	color1 = 0x0000FF00;
	int	color2 = 0x00FF0000;
	if (pixel_bits != 32)
	// 32ビットカラーでない場合に合わせるのかな？
	{
		color = mlx_get_color_value(mlx, color);
		color2 = mlx_get_color_value(mlx, color2);
	}
	for(int y = 0; y < 500; ++y)
	for(int x = 0; x < 500; ++x)
	{
		int pixel = (y * line_bytes) + (x * 4);
		if (x == 250)
			color = color1;
		else
			color = color2;

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
	mlx_put_image_to_window(mlx, win, img, 0, 0);
	mlx_loop(mlx);
}
