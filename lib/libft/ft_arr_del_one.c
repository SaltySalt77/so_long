/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr_del_one.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyna <hyna@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 21:46:05 by hyna              #+#    #+#             */
/*   Updated: 2022/05/27 22:00:50 by hyna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*ft_arr_del_one(int	*arr, int *count, int idx)
{
	int	*new_arr;
	int	i;
	int	j;

	i = 0;
	j = 0;
	new_arr = malloc((*count - 1) * sizeof(int));
	while (j < *count)
	{
		if (j == idx)
		{
			j++;
			continue ;
		}
		new_arr[i] = arr[j]; 
		i++;
		j++;
	}
	*count -= 1;
	free(arr);
	return (new_arr);
}
