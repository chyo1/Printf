/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 16:13:38 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/11/04 15:25:03 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
 # include <stdio.h> //

int		ft_printf(const char *str, ...);
int		div_type(va_list ap, char c, int *cnt);
void	print_atol(long long nbr, char *base, unsigned int div, int *cnt);
int		print_num(va_list ap, int *cnt);
int		print_hex(va_list ap, char lowup, int *cnt);
int		print_addr(va_list ap, int *cnt);
int		print_char(va_list ap, char type, int *cnt);
size_t	ft_strlen(const char *s);
// typedef struct s_list{
// 		zero;
// 		hash;
// 		space;
// 		plus;
// 	//
// 		dash;
// 	 dot;
// }	flag;

#endif