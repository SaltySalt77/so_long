/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyna <hyna@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 19:40:12 by hyna              #+#    #+#             */
/*   Updated: 2022/05/22 20:03:57 by hyna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

void	update_positions(t_img_vars	*head, int type, int x, int y)
{
	t_img_vars	to_change;

	to_change = head;
	while (to_change->type != type && to_change != NULL)
		to_change = to_change->next;
	if (to_change->type == type)
	{
		to_change->xpos = ft_arrjoin(to_change->xpos, x, to_change->count);
		to_change->ypos = ft_arrjoin(to_change->ypos, y, to_change->count);
		to_change->count++;
	}
}
