/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 15:20:23 by wwallas-          #+#    #+#             */
/*   Updated: 2022/06/24 14:56:07 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	numb_house(unsigned long int nbr, int base)
{
	if (nbr < (unsigned long int)base)
		return (1);
	return (numb_house(nbr/base, base) + 1);
}

char	*convert_hex(unsigned long int nbr, int flg)
{
	char	*base_hex;
	char	*result;
	int		size;

	if (nbr == 0)
		return (ft_strdup("0"));
	if (flg == 3 || flg == 7)
		base_hex = BASE_HEX;
	else
		base_hex = BASE_HEX_UP;
	size = numb_house(nbr, 16) + 1;
	result = (char *)malloc(sizeof(char ) * size);
	result[--size] = '\0';
	while (nbr)
	{
		result[--size] = base_hex[(nbr % 16)];
		nbr /= 16;
	}
	return (result);
}

char	*convert_unsigned(unsigned int nbr)
{
	char	*result;
	int		size;

	if (nbr == 0)
		return (ft_strdup("0"));
	size = numb_house(nbr, 10) + 1;
	result = (char *)malloc(sizeof(char ) * size);
	result[--size] = '\0';	
	while (nbr)
	{
		result[--size] = nbr % 10 + 48;
		nbr /= 10;
	}
	return (result);
}
