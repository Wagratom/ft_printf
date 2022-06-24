/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 15:19:35 by wwallas-          #+#    #+#             */
/*   Updated: 2022/06/24 22:11:38 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_zero_unsigned(unsigned int nbr, int size_zero)
{
	int	size;

	size_zero -= numb_house(nbr, 10);
	if (size_zero <= 0)
		return (0);
	size = size_zero;
	while (size--)
		write(1, "0", 1);
	return (size_zero);
}

int	print_unsigned(unsigned int nbr, t_format *data)
{
	int	size;
	int	size_nbr;

	size = verific_precision(nbr, data);
	if (size >= 0)
		return (size);
	size_nbr = numb_house(nbr, 10);
	if (data->precision > size_nbr)
		size_nbr = data->precision;
	size++;
	if (data->numb_spaces > 0)
		size = print_padding(data, size_nbr, 0);
	size += print_unsigned_aux(nbr, data);
	if (data->numb_spaces < 0)
		size += print_padding(data, size_nbr, 0);
	return (size);
}

int	print_unsigned_aux(unsigned int nbr, t_format *data)
{
	char	*result;
	int		size;
	int		index;

	size = 0;
	if (data->precision > 0)
		size = print_zero_unsigned(nbr, data->precision);
	if (nbr == 0)
		return (write(1, "0", 1) + size);
	index = -1;
	result = convert_unsigned(nbr);
	while (result[++index])
		write(1, &result[index], 1);
	free(result);
	return (index + size);
}
