/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 14:46:00 by wwallas-          #+#    #+#             */
/*   Updated: 2022/06/24 22:49:34 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	numb_house_int(long int nbr)
{
	if (nbr < 0)
		nbr = -nbr;
	if (nbr < 10)
		return (1);
	return (numb_house_int(nbr / 10) + 1);
}

int	write_less(long int *nbr, int flg)
{
	if (flg == 1)
		return (*nbr = -*nbr);
	else if (flg == 2)
	{
		write(1, "-", 1);
		*nbr = -*nbr;
	}
	return (1);
}

int	filter_data(long int *nbr, t_format *data)
{
	int	size;

	size = 0;
	if (data->spaces)
	{
		if (*nbr >= 0)
			return (write(1, " ", 1));
		return (write_less(nbr, 2));
	}
	if (data->sig_more)
	{
		if (*nbr >= 0)
			return (write(1, "+", 1));
		return (write_less(nbr, 2));
	}
	if (data->precision > 0)
	{
		size = print_zero((*nbr < 0), data->precision - numb_house_int(*nbr));
		write_less(nbr, (*nbr < 0));
	}
	return (size);
}

int	print_int(int nbr, t_format *data)
{
	int			size_nbr;
	int			size;

	size = verific_precision(nbr, data);
	if (size >= 0)
		return (size);
	size++;
	size_nbr = numb_house_int(nbr);
	if (data->precision > size_nbr)
		size_nbr = data->precision;
	if (data->numb_spaces > 0)
		size = print_padding(data, size_nbr + (nbr < 0), (nbr < 0));
	size += print_int_aux(nbr, data);
	if (data->numb_spaces < 0)
		size += print_padding(data, size_nbr + (nbr < 0), (nbr < 0));
	return (size);
}

int	print_int_aux(long int nbr, t_format *data)
{
	char		*result;
	int			size;
	int			index;

	size = 0;
	if (data->zero && data->numb_spaces && nbr < 0)
		nbr = -nbr;
	size = filter_data(&nbr, data);
	if (nbr == 2147483648)
		return (write(1, "2147483648", 10) + size);
	result = ft_itoa(nbr);
	index = -1;
	while (result[++index])
		write(1, &result[index], 1);
	free(result);
	return (index + size);
}
