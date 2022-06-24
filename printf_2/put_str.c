/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 15:52:53 by wwallas-          #+#    #+#             */
/*   Updated: 2022/06/24 01:57:32 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int print_str(char *str)
{
	int index;

	if (!str)
		return (write(1, "(null)", 6));
	index = -1;
	while (str[++index])
		write(1, &str[index], 1);
	return (index);
}

