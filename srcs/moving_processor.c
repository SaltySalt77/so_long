/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving_processor.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyna <hyna@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 21:42:41 by hyna              #+#    #+#             */
/*   Updated: 2022/05/27 21:45:24 by hyna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_possible_movent(char	**map, t_img_vars	*img, int direction)
{
	int	x;
	int	y;

	x = img->xpos[0];
	y = img->ypos[0];
	if (direction == KEY_UP)
		y--;
	else if (direction == KEY_LEFT)
		x--;
	else if (direction == KEY_DOWN)
		y++;
	else if (direction == KEY_RIGHT)
		x++;
	else
		return (0);
	if (map[y][x] == WALL)
		return (0);
	return (1);
}

int	moving_processor(int keycode, t_mlx_ptr	*mlx_vars)
{
	t_map_size	*map;
	t_img_vars	*player;

	map = mlx_vars->map;
	player = map->img_vars;
	while (player->type != PLAYER)
		player = player->next;
	if (!is_possible_movent(map->map, player, keycode))
		return (1);
	return (0);
}
