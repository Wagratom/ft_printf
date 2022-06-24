/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 20:10:24 by wwallas-          #+#    #+#             */
/*   Updated: 2022/06/24 01:54:28 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

static int	swap(va_list ptr, int flg)
{
	if (flg == 1 || flg == 9)
		return (print_char(va_arg(ptr, int), flg));
	else if (flg == 2)
		return (print_str(va_arg(ptr, char *)));
	else if (flg == 3)
		return (print_pointer(flg, va_arg(ptr, unsigned long int)));
	else if (flg == 4 || flg == 5)
		return (print_int(va_arg(ptr, int)));
	else if (flg == 6)
		return (print_unsigned(va_arg(ptr, unsigned int)));
	else if (flg == 7 || flg == 8)
		return (print_hex(va_arg(ptr, int), flg));
	return (1);
}

int	printf_start(const char *str, va_list ptr)
{	
	int	size;

	size = 0;
	while (*str)
	{
		if (*str == '%')
		{
			size += swap(ptr, verific_mandatory(str + 1));
			str += 2;
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
	va_list		ptr;
	int			size;
	int			index;

	va_start(ptr, str);
	size = 0;
	index = 0;
	while (str[index])
	{
		if (str[index] == '%')
		{
			if (verific_mandatory(&str[index] + 1) <= 0)
				return (0);
			index += 2;
		}
		else
		{
			size++;
			index++;
		}
	}
	size += printf_start(str, ptr);
	va_end(ptr);
	return (size);
}
