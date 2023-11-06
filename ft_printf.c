/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 16:13:09 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/11/06 15:09:52 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	div_type(va_list ap, char c, int *cnt)
{
	// 문자형
	if (c == 'c' || c == 's' || c == '%')
		return (print_char(ap, c, cnt));
	// 주소 출력
	if (c == 'p')
		return (print_addr(ap, cnt));
	// 10진수 int type
	if (c == 'd' || c == 'i' || c == 'u')
		return (print_int_n_uint(ap, c, cnt));
	// 16진수 int type
	if (c == 'x' || c == 'X')
		return (print_hex(ap, c, cnt));
	return (0);
}

int	find_per_or_end(const char *str, size_t *idx, int *cnt)
{
	// 문자열이 끝나거나 %가 나올 때까지 단순 출력
	while (str[*idx] != '\0' && str[*idx] != '%')
	{
		if (write(1, &str[(*idx)++], 1) == -1)
			return (-1);
		(*cnt)++;
	}
	return (1);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	size_t	idx;
	int		cnt;
	int		val;

	// 포인터 변수를 가변인자의 첫 위치로 설정
	va_start(ap, str);
	idx = 0;
	cnt = 0;
	while (str[idx])
	{
		// 단순 출력 처리
		if (find_per_or_end(str, &idx, &cnt) == -1)
			return (-1);
		// 문자열이 끝났거나 %로 끝남 -> 현재까지 출력한 개수 return
		if (str[idx] == '\0' || str[idx + 1] == '\0')
			return (cnt);
		// 자료형 체크 및 출력
		val = div_type(ap, str[idx + 1], &cnt);
		// write error
		if (val == -1)
			return (-1);
		// 잘못된 자료형
		else if (val == 0)
			return (cnt);
		// %_ 뒤로 idx 이동
		idx += 2;
	}
	// 가변인자 처리 끝났을 때 사용한 포인터를 NULL로 초기화
	va_end(ap);
	return (cnt);
}
