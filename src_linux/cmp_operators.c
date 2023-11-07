/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmp_operators.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 19:22:15 by yoda              #+#    #+#             */
/*   Updated: 2023/11/07 07:55:51 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_cmp	square_cmp(t_cmp a)
{
	t_cmp	b;

	b.real = a.real * a.real - a.imag * a.imag;
	b.imag = 2 * a.real * a.imag;
	return (b);
}

t_cmp	multiple_cmp(t_cmp a, t_cmp b)
{
	t_cmp	ans;

	ans.real = a.real * b.real - a.imag * b.imag;
	ans.imag = a.real * b.imag + a.imag * b.real;
	return (ans);
}

t_cmp	cube_cmp(t_cmp a)
{
	t_cmp	tmp;
	t_cmp	ans;

	tmp = square_cmp(a);
	ans = multiple_cmp(tmp, a);
	return (ans);
}

t_cmp	plus_cmp(t_cmp a, t_cmp b)
{
	t_cmp	ans;

	ans.real = a.real + b.real;
	ans.imag = a.imag + b.imag;
	return (ans);
}

t_cmp	minus_cmp(t_cmp a, t_cmp b)
{
	t_cmp	ans;

	ans.real = a.real - b.real;
	ans.imag = a.imag - b.imag;
	return (ans);
}
