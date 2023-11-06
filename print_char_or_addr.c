/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char_or_addr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:30:32 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/11/06 15:12:39 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	n;

	n = 0;
	while (*s)
	{
		n++;
		s++;
	}
	return (n);
}

int	print_char(va_list ap, char type, int *cnt)
{
	char	p;
	char	*str;

	// 문자 1개 처리
	if (type == 'c' || type == '%')
	{
		if (type == 'c')
			p = va_arg(ap, int);
		else
			p = '%';
		if (write(1, &p, 1) == -1)
			return (-1);
		(*cnt)++;
	}

	// 문자열 출력
	else
	{
		str = va_arg(ap, char *);

		// null 처리
		if (str == 0)
			str = "(null)";
		if (write(1, str, ft_strlen(str)) == -1)
			return (-1);
		(*cnt) += ft_strlen(str);
	}
	return (1);
}

// 주소 출력
int	print_addr(va_list ap, int *cnt)
{
	unsigned long long	num;
	int					idx;
	char				base[16];

	num = (unsigned long long)va_arg(ap, int *);
	idx = -1;

	// base를 16진수로
	while (++idx < 10)
		base[idx] = idx + '0';
	while (idx < 16)
	{
		base[idx] = (idx - 10) + 'a';
		idx++;
	}

	// 주소값 앞에 0x 출력
	if (write(1, "0x", 2) == -1)
		return (-1);
	(*cnt) += 2;
	return (print_ultoa(num, base, 16, cnt));
}
