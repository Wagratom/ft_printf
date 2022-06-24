/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rest_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 18:38:35 by wwallas-          #+#    #+#             */
/*   Updated: 2022/06/24 20:02:29 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	padding_mod(const char *str, t_format *data)
{
	int index;
	int	signal_negative;

	index = 0;
	signal_negative = 1;
	if (str[index] == '-')
	{
		index++;
		signal_negative = -1;
	}
	while (str[index] >= '0' && str[index] <= '9')
		data->numb_spaces = (str[index++] - 48) + (data->numb_spaces * 10);
	data->numb_spaces *= signal_negative;
	return (index);
}

int	spaces(const char *str, t_format *data)
{
	int index;

	data->spaces = 1;
	index = 0;
	while (str[index] == ' ')
		index++;
	index += padding_mod(&str[index], data);
	return (index);
}

int	zero(const char *str, t_format *data)
{
	int size;

	size = 1;
	data->zero = 1;
	size += padding_mod(str + 1, data);
	if (str[size] == '.')
		size += precision(&str[size], data);
	return (size);
}

int	hastag(const char *str, t_format *data)
{
	str++;
	return ((data->hashtag = 1));
}

int	sig_more(const char *str, t_format *data)
{
	int index;

	data->sig_more = 1;
	index = 0;
	while (str[index] == '+')
		index++;
	return (index);
}