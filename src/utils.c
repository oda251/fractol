/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 19:22:15 by yoda              #+#    #+#             */
/*   Updated: 2023/10/30 19:22:26 by yoda             ###   ########.fr       */
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