/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyna <hyna@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 21:46:09 by hyna              #+#    #+#             */
/*   Updated: 2022/05/28 06:20:05 by hyna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

static void	is_surrounded_by_walls(t_map_size	*map)
{
	char	*error_message;
	int		i;

	i = 0;
	error_message = "The map must be surrounded by walls.";
	while (i < map->wid)
	{
		if (map->map[0][i] != WALL || map->map[map->ht - 1][i] != WALL)
			put_error_message_exit(error_message, 0);
		i++;
	}
	i = 0;
	while (i < map->ht)
	{
		if (map->map[i][0] != WALL || map->map[i][map->wid - 1] != WALL)
			put_error_message_exit(error_message, 0);
		i++;
	}
}

static void	is_square(t_map_size	*map)
{
	char	*error_message;
	int		i;
	int		wid;

	i = 0;
	error_message = "The map must be square.";
	while (i < map->ht)
	{
		wid = (int) ft_strlen(map->map[i]);
		if (wid != map->wid)
			put_error_message_exit(error_message, 0);
		i++;
	}
}

static void	check_counts(t_map_size	*map)
{
	t_img_vars	*current;

	current = map->img_vars;
	while (current)
	{
		if (current->type == COLECT && current->count < 1)
			put_error_message_exit("Needs at least one collectible.", 0);
		else if (current->type == EXIT && current->count < 1)
			put_error_message_exit("Needs at least one exit.", 0);
		else if (current->type == PLAYER && current->count < 1)
			put_error_message_exit("Needs a starting point.", 0);
		else if (current->type == PLAYER && current->count > 1)
			put_error_message_exit("Needs just one starting point.", 0);
		current = current->next;
	}
}

int	is_map(t_map_size	*map)
{
	is_square(map);
	is_surrounded_by_walls(map);
	get_map_info(map);
	check_counts(map);
	return (1);
}
