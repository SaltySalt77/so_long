/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_p_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyna <hyna@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 15:42:56 by hyna              #+#    #+#             */
/*   Updated: 2022/04/09 15:44:07 by hyna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// 함수명 보고 무슨 함수인지
static int	check_base(char	*str)
{
	int	len;
	int	j;

	len = 0;
	while (str[len])
	{
		if ((str[len] == '+') || (str[len] == '-'))
			return (0);
		j = len + 1;
		while (str[j])
		{
			if ((str[len] == str[j]) || (str[j] == '+') || (str[j] == '-'))
				return (0);
			j++;
		}
		len++;
	}
	return (len);
}

// 파라미터 4개 함수 최대한 지양
static void	print_num(unsigned long long nbr, char *base, int len, int	*result)
{
	char	c;

	if (nbr < (unsigned int)len) // 자료형 맞춰서 비교
	{
		c = base[nbr];
		write(1, &c, 1);
		(*result)++; // 불필요한 괄호
	}
	else
	{
		print_num(nbr / len, base, len, result);
		print_num(nbr % len, base, len, result);
	}
}

// 함수명 
int	conversion_p_util(unsigned long long n, char	*base)
{
	int	len;
	int	result;

	result = 0;
	len = check_base(base);
	if (len == 0 || len == 1) // 괄호
		return (-1);
	else if (n == 0)
		return (write(1, "0", 1));
	else
	{
		print_num(n, base, len, &result);
	}
	return (result);
}
