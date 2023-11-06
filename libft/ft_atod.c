/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 05:25:32 by yoda              #+#    #+#             */
/*   Updated: 2023/11/07 05:46:08 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	is_decimal(char *str)
{
	int		i;
	bool	detect_num;

	detect_num = false;
	i = 0;
	while (str[i] && ft_strchr(SPACE, str[i]) != NULL)
		i++;
	if (str[i] && (str[i] == '+' || str[i] == '-'))
		i++;
	while (str[i] && ('0' <= str[i] && str[i] <= '9'))
	{
		detect_num = true;
		i++;
	}
	if (str[i] && str[i] == '.')
		i++;
	while (str[i] && ('0' <= str[i] && str[i] <= '9'))
		i++;
	if (detect_num && str[i] == '\0')
		return (true);
	return (false);
}

double	ft_atod(char *str)
{
	int			i;
	int			sign;
	double	num;
	double	decimal;

	if (!is_decimal(str))
		return (0);
	num = (double)ft_atoi(str);
	i = 0;
	sign = 1;
	while (str[i] && ft_strchr(SPACE, str[i]) != NULL)
		i++;
	if (str[i] == '-')
		sign = -1;
	while (str[i] && str[i] != '.')
		i++;
	if (str[i] == '\0')
		return (num);
	decimal = (double)ft_atoi(str + i + 1);
	while (decimal >= 1)
		decimal /= 10;
	decimal *= sign;
	return (num + decimal);
}