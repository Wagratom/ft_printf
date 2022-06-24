/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 20:09:58 by wwallas-          #+#    #+#             */
/*   Updated: 2022/06/24 14:56:38 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_pointer(int flg, unsigned long int nbr)
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
