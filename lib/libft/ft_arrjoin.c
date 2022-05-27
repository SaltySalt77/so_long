/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyna <hyna@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 19:28:24 by hyna              #+#    #+#             */
/*   Updated: 2022/05/28 06:06:54 by hyna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*ft_arrjoin(int	*arr, int newnbr, int count)
{
	int	*new_arr;
	int	i;

	i = 0;
	new_arr = malloc(sizeof(int) * (count + 1));
	if (new_arr == NULL)
		return (NULL);
	while (i < count)
	{
		new_arr[i] = arr[i];
		i++;
	}
	new_arr[i] = newnbr;
	if (arr)
		free(arr);
	return (new_arr);
}
