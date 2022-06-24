/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 15:52:53 by wwallas-          #+#    #+#             */
/*   Updated: 2022/06/23 18:30:41 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	size_str(char *str)
{
	if (str == NULL)
		return (6);
	else 
		return (ft_strlen(str));
}

int	print_str_aux(char *str, t_format *data)
{
	int	index;
	int flg;

	index = -1;
	flg = (str == NULL);
	if (!str)
		str = STR_NULL;
	if (data->precision > 0)
	{
		if (flg && data->precision < 6)
			return (0);
		while (str[++index] && data->precision--)
			write(1, &str[index], 1);
		if (data->numb_spaces < 0 && data->precision)
		{
			while (--data->precision > 1)
				index += write(1, " ", 1);
		}
	}
	else
	{
		while (str[++index])
			write(1, &str[index], 1);
	}
	return (index);
}

int	filter_char(t_format *data)
{
	if (data->numb_spaces)
		return (print_padding(data, 0, 0));
	return (0);
}

int	print_str(char *str, t_format *data)
{
	int size;
	int len_str;
	
	size = 0;
	if (!data->precision)
		return (filter_char(data));
	len_str = size_str(str);
	if (data->precision > 0)
		len_str = data->precision;
	if (data->numb_spaces > 0)
		size = print_padding(data, len_str, 0);
	size += print_str_aux(str, data);
	if (data->numb_spaces < 0)
		size += print_padding(data, len_str, 0);
	return (size);
}

