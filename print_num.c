/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 18:34:23 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/11/06 15:38:29 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_int_n_uint(va_list ap, char c, int *cnt)
{
	long long	num;
	int			idx;
	char		base[10];

	num = va_arg(ap, int);
	idx = -1;
	// base를 10진수로
	while (++idx < 10)
		base[idx] = idx + '0';
	// unsigned로 형변환 후 넘김
	if (c == 'u')
		return (print_utoa((unsigned int) num, base, 10, cnt));
	else
		return (print_ltoa(num, base, 10, cnt));
}

int	print_utoa(unsigned int num, char *base, size_t div, int *cnt)
{
	char		print[32];
	int			idx;

	idx = 0;
	if (num == 0)
	{
		if (write(1, &base[0], 1) == -1)
			return (-1);
		(*cnt)++;
		return (1);
	}
	while (num > 0)
	{
		print[idx++] = base[num % div];
		num /= div;
	}
	(*cnt) += idx;
	while (idx > 0)
	{
		if (write(1, &print[--idx], 1) == -1)
			return (-1);
	}
	return (1);
}

int	print_ultoa(unsigned long long num, char *base, size_t div, int *cnt)
{
	char		print[32];
	int			idx;

	idx = 0;
	if (num == 0)
	{
		if (write(1, &base[0], 1) == -1)
			return (-1);
		(*cnt)++;
		return (1);
	}
	while (num > 0)
	{
		print[idx++] = base[num % div];
		num /= div;
	}
	(*cnt) += idx;
	while (idx > 0)
	{
		if (write(1, &print[--idx], 1) == -1)
			return (-1);
	}
	return (1);
}

int	print_ltoa(long long num, char *base, size_t div, int *cnt)
{
	int			idx;

	idx = 0;
	if (num < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		num = -num;
		(*cnt)++;
	}
	return (print_ultoa(num, base, div, cnt));
}

// int형 16진수로 출력
int	print_hex(va_list ap, char lowup, int *cnt)
{
	unsigned int		num;
	int					idx;
	char				base[16];
	char				alpha;

	num = (unsigned int)va_arg(ap, int);
	idx = -1;
	while (++idx < 10)
		base[idx] = idx + '0';

	// 문자 출력시 대소문자 설정
	if (lowup == 'x')
		alpha = 'a';
	else
		alpha = 'A';

	// base를 16진수로
	while (idx < 16)
	{
		base[idx] = (idx - 10) + alpha;
		idx++;
	}
	return (print_ltoa(num, base, 16, cnt));
	return (1);
}
