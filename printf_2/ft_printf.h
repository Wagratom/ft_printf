/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 04:51:27 by wwallas-          #+#    #+#             */
/*   Updated: 2022/06/24 20:06:49 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF
#define FT_PRINTF

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

#define BASE_HEX "0123456789abcdef"
#define BASE_HEX_UP "0123456789ABCDEF"
#define STR_NULL "(null)"

//my functions in convert file
//count numb of houses
int		numb_house(unsigned long int nbr, int base);

//convert one integer for hex the return one string
char	*convert_hex(unsigned long int nbr, int flg);

//convert one integer for one string
char	*convert_unsigned(unsigned int nbr);

//my functions madatory
int		ft_printf(const char *str, ...);
int		print_hex(unsigned int nbr, int flg);
int		print_int(int nbr);
int		print_pointer(int flg, unsigned long int nbr);
int		print_unsigned(unsigned int nbr);
int		print_char(int c, int flg);
int		print_str(char *str);

#endif