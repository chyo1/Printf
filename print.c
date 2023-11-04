/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 18:34:23 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/11/04 19:38:56 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_num(va_list ap, int *cnt)
{
	long long	num;
	int			idx;
	char		base[10];

	num = va_arg(ap, int);
	idx = -1;
	while (++idx < 10)
		base[idx] = idx + '0';
	print_atol(num, base, 10, cnt);
	return (1);
}

int	print_hex(va_list ap, char lowup, int *cnt)
{
	int		num;
	int		idx;
	char	base[16];
	char	alpha;

	num = va_arg(ap, int);
	idx = -1;
	while (++idx < 10)
		base[idx] = idx + '0';
	if (lowup == 'x')
		alpha = 'a';
	else
		alpha = 'A';
	while (idx < 16)
	{
		base[idx] = (idx - 10) + alpha;
		idx++;
	}
	print_atol(num, base, 16, cnt);
	return (1);
}

int	print_addr(va_list ap, int *cnt)
{
	long long	num;
	int			idx;
	char		base[16];

	num = (long long)va_arg(ap, int *);
	idx = -1;
	while (++idx < 10)
		base[idx] = idx + '0';
	while (idx < 16)
	{
		base[idx] = (idx - 10) + 'a';
		idx++;
	}
	write(1, "0x", 2);
	(*cnt) += 2;
	print_atol(num, base, 16, cnt);
	return (1);
}

int	print_char(va_list ap, char type, int *cnt)
{
	char	p;
	char	*str;

	if (type == 'c')
	{
		p = va_arg(ap, int);
		write(1, &p, 1);
		(*cnt)++;
	}
	else if (type == '%')
	{
		write(1, "%", 1);
		(*cnt)++;
	}
	else
	{
		str = va_arg(ap, char *);
		if (str == 0)
			str = "(null)";
		write(1, str, ft_strlen(str));
		(*cnt) += ft_strlen(str);
	}
	return (1);
}

void	print_atol(long long num, char *base, unsigned int div, int *cnt)
{
	char		print[32];
	int			idx;

	idx = 0;
	if (num < 0)
	{
		write(1, "-", 1);
		num = -num;
		(*cnt)++;
	}
	else if (num == 0)
	{
		write(1, &base[0], 1);
		(*cnt)++;
		return ;
	}
	while (num > 0)
	{
		print[idx++] = base[num % div];
		num /= div;
	}
	(*cnt) += idx;
	while (idx > 0)
		write(1, &print[--idx], 1);
	return ;
}
