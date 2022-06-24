/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 12:40:24 by wwallas-          #+#    #+#             */
/*   Updated: 2022/06/22 01:23:18 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	precision(const char *str, t_format *data)
{
	int	index;

	str++;
	index = 0;
	data->precision = 0;
	while (str[index] >= '0' && str[index] <= '9')
		data->precision = (str[index++] - 48) + (data->precision * 10);
	return (index + 1);
}