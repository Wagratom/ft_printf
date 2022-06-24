/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_padding.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 21:35:37 by wwallas-          #+#    #+#             */
/*   Updated: 2022/06/24 21:36:09 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_zero(int flg, int size)
{
	int	cpy;

	cpy = size;
	if (flg)
		write(1, "-", 1);
	if (size <= 0)
		return (flg);
	while (size--)
		write(1, "0", 1);
	return (cpy + flg);
}

int	print_padding(t_format *data, int size_str, int flg)
{
	int	size;

	if (data->numb_spaces < 0)
		data->numb_spaces = -data->numb_spaces;
	data->numb_spaces -= size_str;
	if (data->numb_spaces <= 0)
		return (data->zero = 0);
	size = data->numb_spaces;
	if (data->zero && data->precision <= 0)
		return (print_zero(flg, size));
	while (size--)
		write(1, " ", 1);
	if (data->zero && flg)
		data->numb_spaces += write(1, "-", 1);
	return (data->numb_spaces);
}
