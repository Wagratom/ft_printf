/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 19:37:04 by wwallas-          #+#    #+#             */
/*   Updated: 2022/06/24 20:08:27 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
#define FT_PRINTF_BONUS_H

#include "../ft_printf.h"

int		ft_printf_bonus(const char *str, ...);

int		print_hex_bonus(unsigned int nbr, int flg, t_format *data);
int		print_hex_aux(unsigned int nbr, int flg, t_format *data);

int		print_int_bonus(int nbr, t_format *data);
int		print_int_aux(long int nbr, t_format *data);

int		print_pointer_bonus(int flg, t_format *data, unsigned long int nbr);
int		print_pointer_aux(int flg, unsigned long int nbr);

int		print_unsigned_bonus(unsigned int nbr, t_format *data);
int		print_unsigned_aux(unsigned int nbr, t_format *data);

int		print_char_bonus(int c, int flg, t_format *data);

int		print_str_bonus(char *str, t_format *data);


int		verific_bonus(const char *str, t_format *data);
int		precision(const char *str, t_format *data);
int		sig_more(const char *str, t_format *data);
int		padding(const char *str, t_format *data);
int		spaces(const char *str, t_format *data);
int		hastag(const char *str, t_format *data);
int		zero(const char *str, t_format *data);
int		print_zero(int flg, int size);
int		verific_precision(int nbr, t_format *data);
int		print_padding(t_format *data, int size_str, int flg);


#endif