/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 16:13:09 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/11/04 19:37:51 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	div_type(va_list ap, char c, int *cnt)
{
	if (c == 'd' || c == 'i' || c == 'u')
		return (print_num(ap, cnt));
	if (c == 'x' || c == 'X')
		return (print_hex(ap, c, cnt));
	if (c == 'p')
		return (print_addr(ap, cnt));
	if (c == 'c' || c == 's' || c == '%')
		return (print_char(ap, c, cnt));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	size_t	idx;
	int		cnt;

	va_start(ap, str);
	idx = 0;
	cnt = 0;
	while (str[idx])
	{
		while (str[idx] != '\0' && str[idx] != '%')
		{
			write(1, &str[idx++], 1);
			cnt++;
		}
		if (str[idx] == '\0')
			return (cnt);
		else if (str[idx] == '%')
		{
			if (str[idx + 1] == '\0' || !div_type(ap, str[idx + 1], &cnt))
				return (cnt);
			idx += 2;
		}
	}
	va_end(ap);
	return (cnt);
}

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

// int main()
// {
// 	char *str = " %p ";
// 	// int *a;
// 	printf("ft_printf_re : %d\n", ft_printf(str, NULL));
// 	printf("\n printf_re : %d", printf(" %p ", 2147483647));
// }
