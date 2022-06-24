/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 20:09:58 by wwallas-          #+#    #+#             */
/*   Updated: 2022/06/24 21:49:15 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_pointer(int flg, t_format *data, unsigned long int nbr)
{
	int	size;
	int	temp;

	size = 0;
	temp = numb_house(nbr, 16) + 2;
	if (!nbr)
		temp = 5;
	if (data->numb_spaces > 0)
		size = print_padding(data, temp, 0);
	size += print_pointer_aux(flg, nbr);
	if (data->numb_spaces < 0)
		size += print_padding(data, temp, 0);
	return (size);
}

int	print_pointer_aux(int flg, unsigned long int nbr)
{
	char	*result;
	int		index;

	if (nbr == 0)
		return (write(1, "(nil)", 5));
	write(1, "0x", 2);
	result = convert_hex(nbr, flg);
	index = -1;
	while (result[++index])
		write(1, &result[index], 1);
	free(result);
	return (index + 2);
}
