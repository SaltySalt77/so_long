/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyna <hyna@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 19:12:26 by hyna              #+#    #+#             */
/*   Updated: 2022/05/27 19:59:32 by hyna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	put_objects(void	*mlx, void	*win, t_img_vars	*img)
{
	int i;
	int	x;
	int y;

	i = 0;
	while (i < img->count)
	{
		x = SIZE * img->xpos[i];
		y = SIZE * img->ypos[i];
		mlx_put_image_to_window(mlx, win, img->img_ptr, x, y);
		i++;
	}
}

static void	put_background(void	*mlx, void	*win, t_map_size	*map)
{
	t_img_vars	*img;
	int			i;
	int			j;

	img = map->img_vars;
	i = 0;
	while (i < map->ht)
	{
		j = 0;
		while (j < map->wid)
		{
			mlx_put_image_to_window(mlx, win, img->img_ptr, j * SIZE, i * SIZE);
			j++;
		}
		i++;
	}
}

void	load_map(t_mlx_ptr	mlx_vars, t_map_size	*map)
{
	t_img_vars	*img;

	img = map->img_vars;
	put_background(mlx_vars.mlx, mlx_vars.win, map);
	while (img)
	{
		put_objects(mlx_vars.mlx, mlx_vars.win, img);
		img = img->next;
	}
}
