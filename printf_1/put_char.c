/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_char.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 15:52:53 by wwallas-          #+#    #+#             */
/*   Updated: 2022/06/23 18:49:05 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char_aux(int c, int flg)
{
	if (flg == 1)
		write(1, &c, 1);
	else
		write(1, "%", 1);
	return (1);
}

int	print_char(int c, int flg, t_format *data)
{
	unsigned int	size;

	size = 0;
	if (data->numb_spaces > 0)
		size = print_padding(data, 1, 0);
	size += print_char_aux(c, flg);
	if (data->numb_spaces < 0)
		size += print_padding(data, 1, 0);
	return (size);
}
