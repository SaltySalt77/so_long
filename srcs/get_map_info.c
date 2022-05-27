/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyna <hyna@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 21:46:26 by hyna              #+#    #+#             */
/*   Updated: 2022/05/28 06:19:17 by hyna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

static void	update_positions(t_img_vars	*head, int type, int x, int y)
{
	t_img_vars	*to_change;

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

static t_img_vars	*new_img_vars(int type)
{
	t_img_vars	*new;

	new = malloc(sizeof(t_img_vars));
	if (!new)
		put_error_message_exit("new_img_vars ", 1);
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
	current->type = AIR;
	current->count = 0;
	current->xpos = NULL;
	current->ypos = NULL;
	current->next = NULL;
	current->next = new_img_vars(WALL);
	current = current->next;
	current->next = new_img_vars(COLECT);
	current = current->next;
	current->next = new_img_vars(EXIT);
	current = current->next;
	current->next = new_img_vars(PLAYER);
	return (head);
}

static void	put_info_in_img_vars(t_map_size	*map, t_img_vars	*head)
{
	int			y;
	int			x;

	y = 0;
	while (y < map->ht)
	{
		x = 0;
		while (x < map->wid)
		{
			if (map->map[y][x] == WALL)
				update_positions(head, WALL, x, y);
			else if (map->map[y][x] == COLECT)
				update_positions(head, COLECT, x, y);
			else if (map->map[y][x] == EXIT)
				update_positions(head, EXIT, x, y);
			else if (map->map[y][x] == PLAYER)
				update_positions(head, PLAYER, x, y);
			else if (map->map[y][x] != AIR)
				put_error_message_exit("Map mustn't have anouther alphabet", 0);
			x++;
		}
		y++;
	}
}

void	get_map_info(t_map_size	*map)
{
	t_img_vars	*head;

	head = malloc(sizeof(t_img_vars));
	map->img_vars = put_types_in_img_vars(head);
	put_info_in_img_vars(map, head);
}
