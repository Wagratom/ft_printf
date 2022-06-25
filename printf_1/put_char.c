/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_char.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 15:52:53 by wwallas-          #+#    #+#             */
/*   Updated: 2022/06/24 23:37:38 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(int c, t_format *data)
{
	unsigned int	size;

	size = 0;
	if (data->numb_spaces > 0)
		size = print_padding(data, 1, 0);
	size += write(1, &c, 1);
	if (data->numb_spaces < 0)
		size += print_padding(data, 1, 0);
	return (size);
}
