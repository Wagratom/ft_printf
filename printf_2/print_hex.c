/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 15:45:18 by wwallas-          #+#    #+#             */
/*   Updated: 2022/06/24 14:56:41 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hex(unsigned int nbr, int flg)
{
	char	*result;
	int		index;

	result = convert_hex(nbr, flg);
	index = -1;
	while (result[++index])
		write(1, &result[index], 1);
	free(result);
	return (index);
}
