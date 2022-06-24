/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 15:45:18 by wwallas-          #+#    #+#             */
/*   Updated: 2022/06/23 18:56:23 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int print_zero_hex(int size, int size_zero)
{
	int index;

	size_zero -= size;
	if (size_zero <= 0)
		return (0);
	index = size_zero;
	while (index--)
		write(1, "0", 1);
	return (size_zero);
}

static int filter_hex(t_format *data)
{
	if (data->precision > 0)
		return (print_zero_hex(0, data->precision));
	if (data->precision < 0)
		return (write(1, "0", 1));
	return (0);
}

int	print_hex_aux(unsigned int nbr, int flg, t_format *data)
{
	char	*result;
	int		index;
	int		size;

	if (!nbr)
		return (filter_hex(data));
	result = convert_hex(nbr, flg);
	size = 0;
	if (data->hashtag)
	{
		if (flg == 7)
			size = write(1, "0x", 2);
		else
			size = write(1, "0X", 2);
	}
	if (data->precision > 0)
		size = print_zero_hex(ft_strlen(result), data->precision);
	index = -1;
	while (result[++index])
		write(1, &result[index], 1);
	free(result);
	return (index + size);
}

int	print_hex(unsigned int nbr, int flg, t_format *data)
{
	int	size_nbr;
	int size;

	size = verific_precision(nbr, data);
	if (size >= 0)
		return (size);
	size++;
	size_nbr = numb_house(nbr, 16);
	if (data->precision > size_nbr)
		size_nbr = data->precision;
	if (!data->precision && !nbr)
		size_nbr = 0;
	if (data->numb_spaces > 0)
		size += print_padding(data, size_nbr, 0);
	size += print_hex_aux(nbr, flg, data);
	if (data->numb_spaces < 0)
		size += print_padding(data, size_nbr, 0);
	return (size);
}
