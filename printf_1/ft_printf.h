/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 04:51:27 by wwallas-          #+#    #+#             */
/*   Updated: 2022/06/24 22:29:59 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_format
{
	int	numb_spaces;
	int	spaces;
	int	zero;
	int	hashtag;
	int	sig_more;
	int	precision;
}	t_format;

# define BASE_HEX "0123456789abcdef"
# define BASE_HEX_UP "0123456789ABCDEF"
# define STR_NULL "(null)"

//				my functions in convert file

//count the numb of houses in an integer 
int		numb_house(unsigned long int nbr, int base);

//convert a numb to a string hex
char	*convert_hex(unsigned long int nbr, int flg);

//convert a numb to a string unsigned
char	*convert_unsigned(unsigned int nbr);
//_________________________________________________________

//my copy 
int		ft_printf(const char *str, ...);

//indectate the number of spaces or zeros in print
int		padding(const char *str, t_format *data);

//counts the number of characters to be printed
int		precision(const char *str, t_format *data);

//checks if it exists as bonus flags
int		verific_bonus(const char *str, t_format *data);

//count o numb of sig "+" and activastes sig_more in the strucjt
int		sig_more(const char *str, t_format *data);

//put a space before print
int		spaces(const char *str, t_format *data);

//active hashtag in the struct
int		hashtag(const char *str, t_format *data);

//active zero in the struct
int		zero(const char *str, t_format *data);

//indectate the print with zero
int		print_zero(int flg, int size);

//check if is precision activated e what is your size
int		verific_precision(int nbr, t_format *data);

//indectate o print 
int		print_padding(t_format *data, int size_str, int flg);

//check if a string 
int		ft_printf(const char *str, ...);
int		print_int_aux(long int nbr, t_format *data);

//convert an numb string and print the string in format hex
int		print_hex(unsigned int nbr, int flg, t_format *data);
int		print_hex_aux(unsigned int nbr, int flg, t_format *data);

//convert an intefer to string and print the string formats
int		print_int(int nbr, t_format *data);
int		print_int_aux(long int nbr, t_format *data);

//convert a numb to string and print the string formats in pointer
int		print_pointer(int flg, t_format *data, unsigned long int nbr);
int		print_pointer_aux(int flg, unsigned long int nbr);

//convert an unsigned to string and print the string formats
int		print_unsigned(unsigned int nbr, t_format *data);
int		print_unsigned_aux(unsigned int nbr, t_format *data);

//print a char formatted
int		print_char(int c, int flg, t_format *data);

//print a str formatted
int		print_str(char *str, t_format *data);
int		print_str_aux(char *str, t_format *data);

#endif