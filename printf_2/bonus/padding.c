/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 16:20:57 by wwallas-          #+#    #+#             */
/*   Updated: 2022/06/24 20:01:58 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	verific_str(const char *str, t_format *data)
{
	if (*str == '+')
		data->sig_more = 1;
	else if (*str == ' ')
		data->spaces = 1;
	else if (*str == '#')
		data->hashtag = 1;
	else if ('.')
		return (precision(str, data));
	return (1);
}

int	padding(const char *str, t_format *data)
{
	int	index;
	int	signal_negative;

	index = 0;
	signal_negative = 1;
	while (str[index] == '-')
	{
		index++;
		signal_negative = -1;
	}
	if (str[index] == '+' || str[index] == ' ' || str[index] == '#')
		index += verific_str(str, data);
	while (str[index] >= '0' && str[index] <= '9')
		data->numb_spaces = (str[index++] - 48) + (data->numb_spaces * 10);
	if (str[index] == '.')
		index += verific_str(&str[index], data);
	data->numb_spaces *= signal_negative;
	return (index);
}

