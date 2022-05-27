/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init_processor.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyna <hyna@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 16:20:15 by hyna              #+#    #+#             */
/*   Updated: 2022/05/27 17:54:56 by hyna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"
#include "libft.h"

static void	get_map_size(t_map_size	*map)
{
	int	height;

	height = 0;
	while (map->map[height] != NULL)
		height++;
	map->height = height;
	map->width = ft_strlen(map->map[0]);
}

static char	*read_and_restore_map(char	*map_file)
{
	int		fd;
	char	*map_str;
	char	*new_str;

	map_str = malloc(1);
	fd = open(map_file, O_RDONLY, 00444);
	if (fd < 0)
		return (0);
	while (1)
	{
		new_str = get_next_line(fd);
		if (new_str == NULL)
			break ;
		map_str = ft_strjoin_free(map_str, new_str);
		if (map_str == NULL)
			return (0);
	}
	close(fd);
	return (map_str);
}

int	map_processor(char	*map_file, t_map_size	*map)
{
	char	*map_str;

	map_str = read_and_restore_map(map_file);
	map->map = ft_split(map_str, '\n');
	if (map->map == NULL)
		return (0);
	get_map_size(map);
	is_map(map);
	return (1);
}
