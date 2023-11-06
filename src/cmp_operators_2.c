/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmp_operators_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 07:21:45 by yoda              #+#    #+#             */
/*   Updated: 2023/11/07 07:56:42 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_cmp	real_to_cmp(double real)
{
	t_cmp	cmp;

	cmp.real = real;
	cmp.imag = 0.0;
	return (cmp);
}

t_cmp	devide_cmp(t_cmp a, t_cmp b)
{
	t_cmp	cmp;
	double	tmp;

	tmp = b.real * b.real + b.imag * b.imag;
	cmp.real = (a.real * b.real + a.imag * b.imag) / tmp;
	cmp.imag = (a.imag * b.real - a.real * b.imag) / tmp;
	return (cmp);
}
