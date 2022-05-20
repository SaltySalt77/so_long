/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_in_conversions1.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyna <hyna@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 19:30:04 by hyna              #+#    #+#             */
/*   Updated: 2022/04/09 15:05:31 by hyna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	conversion_c(va_list	ap)
{
	int		result;
	char	c;

	c = va_arg(ap, int); // va_arg 2nd param
	result = write(1, &c, 1);
	return (result);
}

int	conversion_s(va_list	ap)
{
	int		result;
	char	*s;

	s = va_arg(ap, char *);
	if (!s) // <- 지양 // 클린코드, 리팩토링, 유지보수하기어렵게코딩하는법
		return (write(1, "(null)", 6)); // 문자열 매크로 // 특정 상수 매직넘버 지양
	result = write(STDOUT_FILENO, s, ft_strlen(s));
	return (result);
}

int	conversion_di(va_list	ap)
{
	int		result;
	int		num;
	char	*s; // 알파벳 하나짜리 변수명 지양

	num = va_arg(ap, int);
	s = ft_itoa(num);
	if (!s) // 부정
		return (-1); // 매직넘버
	result = write(1, s, ft_strlen(s));
	free(s);
	s = NULL;
	return (result);
}
