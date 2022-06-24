/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verific_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 19:02:56 by wwallas-          #+#    #+#             */
/*   Updated: 2022/06/24 20:02:32 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	verific_bonus(const char *str, t_format *data)
{
	if (*str == '-' || (*str >= '1' && *str <= '9'))
		return (padding(str, data));
	else if (*str == '.')
		return (precision(str, data));
	else if (*str == '0')
		return(zero(str, data));
	else if (*str == ' ')
		return (spaces(str, data));
	else if (*str == '#')
		return (hastag(str, data));
	else if (*str == '+')
		return (sig_more(str, data));
	return (0);
}