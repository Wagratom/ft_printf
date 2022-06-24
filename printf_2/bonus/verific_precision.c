/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verific_precision.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 00:18:21 by wwallas-          #+#    #+#             */
/*   Updated: 2022/06/24 20:02:35 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int filter_int(t_format *data)
{
	int cpy;

	cpy = data->numb_spaces;
	if (data->zero)
	{
		while (data->numb_spaces--)
			write(1, " ", 1);
		return (cpy);
	}
	else if (data->numb_spaces)
		return (print_padding(data, 0, 0));
	return (0);
}

int	verific_precision(int nbr, t_format *data)
{
	if (!data->precision)
	{
		if (!nbr || (data->zero && !nbr))
			return (filter_int(data));
	}
	return (-1);
}