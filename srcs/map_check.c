/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyna <hyna@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 18:06:09 by hyna              #+#    #+#             */
/*   Updated: 2022/05/22 20:45:35 by hyna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_map(t_map_size	map)
{
	int	i;

	i = 0;
	while (i < map.width)
	{
		if (map.map[0][i] != WALL || map.map[map.height - 1][i] != WALL)
		{
			printf("%c %c\n", map.map[0][i], map.map[map.height - 1][i]);
			return (0);
		}
		i++;
	}
	i = 0;
	while (i < map.height)
	{
		if (map.map[i][0] != WALL || map.map[i][map.width - 1] != WALL)
			return (0);
		i++;
	}
	return (1);
}

static t_img_vars	*new_img_vars(int type)
{
	t_img_vars	*new;

	new = malloc(sizeof(t_img_vars));
	if (!new)
		return (NULL);
	new->type = type;
	new->count = 0;
	new->xpos = NULL;
	new->ypos = NULL;
	new->next = NULL;
	return (new);
}

static t_img_vars	*put_types_in_img_vars(t_img_vars	*head)
{
	t_img_vars	*current;

	current = head;
	current->type = WALL;
	new->count = 0;
	new->xpos = NULL;
	new->ypos = NULL;
	new->next = NULL;
	current->next = new_img_vars(COLECT);
	current = current->next;
	current->next = new_img_vars(EXIT);
	current = current->next;
	current->next = new_img_vars(PLAYER);
	return (head);
}	

t_map_size	get_map_info(t_map_size	map)
{
	t_img_vars	*head;
	int			y;
	int			x;

	y = 0;
	head = malloc(sizeof(t_img_vars));
	map.img_vars = put_types_in_img_vars(head);
	while (y < map.height)
	{
		x = 0;
		while (x < map.width)
		{
			if (map.map[y][x] == WALL)
				update_positions(head, WALL, j, i);
			else if (map.map[y][x] == COLECT)
				update_positions(head, COLECT, j, i);
			else if (map.map[y][x] == EXIT)
				update_positions(head, EXIT, j, i);
			else if (map.map[y][x] == PLAYER)
				update_positions(head, PLAYER, j, i);
			else if (map.map[y][x] != AIR)
				put_error_message_exit("Error! map has anouther alphabet.", 0);
			x++;
		}
		y++;
	}
	return (map);
}
