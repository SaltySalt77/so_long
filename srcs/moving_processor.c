/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving_processor.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyna <hyna@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 21:42:41 by hyna              #+#    #+#             */
/*   Updated: 2022/05/28 01:20:37 by hyna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

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
	img->xpos = ft_arrjoin(img->xpos, x, 1);
	img->ypos = ft_arrjoin(img->ypos, y, 1);
	img->count += 1;
	return (1);
}

t_img_vars	*find_img_info(t_img_vars	*img, int	type)
{
	t_img_vars	*find;

	find = img;
	while (find->type != type)
		find = find->next;
	return (find);
}

int	get_dest_type(char	**map, t_img_vars	*player)
{
	int	type;
	int	x;
	int	y;
	
	x = player->xpos[1];
	y = player->ypos[1];
	type = map[y][x];
	return (type);
}

int	moving_processor(int keycode, t_mlx_ptr	*mlx_vars)
{
	t_map_size	*map;
	t_img_vars	*player;
	int			type;

	map = mlx_vars->map;
	player = find_img_info(map->img_vars, PLAYER);
	if (!is_possible_movent(map->map, player, keycode))
		return (1);
	mv_player(mlx_vars, map->map, map->img_vars);
	return (0);
}
