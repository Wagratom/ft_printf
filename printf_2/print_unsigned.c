/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 15:19:35 by wwallas-          #+#    #+#             */
/*   Updated: 2022/06/24 14:55:45 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_unsigned(unsigned int nbr)
{
	char	*result;
	int		index;


	result = convert_unsigned(nbr);
	index = -1;
	while (result[++index])
		write(1, &result[index], 1);
	free(result);
	return (index);
}
