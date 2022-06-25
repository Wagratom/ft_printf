/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 20:10:24 by wwallas-          #+#    #+#             */
/*   Updated: 2022/06/24 23:58:21 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_format	*init_data(void)
{
	t_format	*new;

	new = (t_format *)malloc(sizeof(t_format));
	new->numb_spaces = 0;
	new->spaces = 0;
	new->zero = 0;
	new->hashtag = 0;
	new->sig_more = 0;
	new->precision = -1;
	return (new);
}

static int	verific_mandatory(const char *str)
{
	if (*str == 'c')
		return (1);
	else if (*str == 's')
		return (2);
	else if (*str == 'p')
		return (3);
	else if (*str == 'd')
		return (4);
	else if (*str == 'i')
		return (5);
	else if (*str == 'u')
		return (6);
	else if (*str == 'x')
		return (7);
	else if (*str == 'X')
		return (8);
	else if (*str == '%')
		return (9);
	else
		return (-1);
}

static int	swap(va_list ptr, int flg, t_format *data)
{
	if (flg == 1)
		return (print_char(va_arg(ptr, int), data));
	else if (flg == 2)
		return (print_str(va_arg(ptr, char *), data));
	else if (flg == 3)
		return (print_pointer(flg, data, va_arg(ptr, unsigned long int)));
	else if (flg == 4 || flg == 5)
		return (print_int(va_arg(ptr, int), data));
	else if (flg == 6)
		return (print_unsigned(va_arg(ptr, unsigned int), data));
	else if (flg == 7 || flg == 8)
		return (print_hex(va_arg(ptr, int), flg, data));
	else if (flg == 9)
		return (write(1, "%", 1));
	return (1);
}

int	printf_start(const char *str, va_list ptr)
{
	t_format	*data;	
	int			size;

	size = 0;
	while (*str)
	{
		if (*str == '%')
		{
			data = init_data();
			str += verific_bonus(str + 1, data) + 1;
			size += swap(ptr, verific_mandatory(str), data);
			str++;
			free(data);
		}
		else
		{
			write(1, str, 1);
			str++;
		}
	}
	return (size);
}

int	ft_printf(const char *str, ...)
{
	t_format	*temp;
	va_list		ptr;
	int			size;
	int			index;

	va_start(ptr, str);
	temp = init_data();
	index = -1;
	size = 0;
	while (str[++index])
	{
		if (str[index] == '%')
		{
			index += verific_bonus(&str[index + 1], temp) + 1;
			if (verific_mandatory(&str[index]) <= 0)
				return (free(temp), 0);
		}
		else
			size++;
	}
	size += printf_start(str, ptr);
	free(temp);
	va_end(ptr);
	return (size);
}
