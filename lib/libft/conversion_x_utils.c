/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_x_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyna <hyna@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 15:28:19 by hyna              #+#    #+#             */
/*   Updated: 2022/04/09 16:04:43 by hyna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// 좋은 함수를 만드는 방법
// 1. 가장 최소 단위로 하나의 역할만 하는 함수로 만든다
// 2. 함수명은 동사 + 명사 ex) handle_xxx_error()

static int	result_len(long long n, int base_len)
{
	int	len;

	len = 1;
	if (n <= 0)
		len++;
	while (n)
	{
		n /= base_len;
		len++;
	}
	return (len);
}

// 함수명
static void	ft_rev(char	*tab, int size)
{
	char	temp;
	int		i;
	int		j;

	i = size - 1;
	j = 0;
	while (j < size / 2)
	{
		temp = tab[j];
		tab[j] = tab[i];
		tab[i] = temp;
		i--;
		j++;
	}
}

static void	make_result(long long n, char	*result, int pos, char	*base)
{
	int	i;
	int	base_len;

	base_len = ft_strlen(base);
	i = 0;
	while (i < pos)
	{
		result[i] = base[n % base_len];
		n /= base_len;
		i++;
	}
	ft_rev(result, ft_strlen(result));
}

char	*ft_itoa_base(unsigned int n, char	*base)
{
	char	*result;

	result = (char *) ft_calloc(result_len(n, ft_strlen(base)), sizeof(char));
	if (result == NULL)
		return (NULL);
	// make_result
	make_result(n, result, result_len(n, ft_strlen(base)) - 1, base);
	return (result);
}
