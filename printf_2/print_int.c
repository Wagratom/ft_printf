/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 14:46:00 by wwallas-          #+#    #+#             */
/*   Updated: 2022/06/24 02:03:10 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_int(int nbr)
{
	char	*result;
	int		index;

	result = ft_itoa(nbr);
	index = -1;
	while (result[++index])
		write(1, &result[index], 1);
	free(result);
	return (index);
}
