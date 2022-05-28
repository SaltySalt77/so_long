/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mv_player.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyna <hyna@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 23:12:16 by hyna              #+#    #+#             */
/*   Updated: 2022/05/28 09:37:29 by hyna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

static void	mv_from_exit(t_mlx_ptr	*mlx, char	**map, t_img_vars	*img)
{
	t_img_vars	*curt;
	int			x;
	int			y;
	int			type;

	curt = find_img_info(img, PLAYER);
	x = curt->xpos[0];
	y = curt->ypos[0];
	map[y][x] = EXIT;
	type = get_dest_type(map, curt);
	curt = find_img_info(img, AIR);
	x *= SIZE;
	y *= SIZE;
	mlx_put_image_to_window(mlx->mlx, mlx->win, curt->img_ptr, x, y);
	curt = find_img_info(img, EXIT);
	mlx_put_image_to_window(mlx->mlx, mlx->win, curt->img_ptr, x, y);
	if (type == COLECT)
		mv_to_colect(mlx, map, img);
	else if (type == EXIT)
		mv_to_exit(mlx, map, img);
	else
		mv_to_air(mlx, map, img);
}

static void	mv_from_air(t_mlx_ptr	*mlx, char	**map, t_img_vars	*img)
{
	t_img_vars	*curt;
	int			x;
	int			y;
	int			type;

	curt = find_img_info(img, PLAYER);
	x = curt->xpos[0];
	y = curt->ypos[0];
	map[y][x] = AIR;
	type = get_dest_type(map, curt);
	curt = find_img_info(img, AIR);
	x *= SIZE;
	y *= SIZE;
	mlx_put_image_to_window(mlx->mlx, mlx->win, curt->img_ptr, x, y);
	if (type == COLECT)
		mv_to_colect(mlx, map, img);
	else if (type == EXIT)
		mv_to_exit(mlx, map, img);
	else
		mv_to_air(mlx, map, img);
}

static int	starting_pt_is_exit(t_img_vars	*img)
{
	t_img_vars	*curt;
	int			x;
	int			y;
	int			i;

	i = 0;
	curt = find_img_info(img, PLAYER);
	x = curt->xpos[0];
	y = curt->ypos[0];
	curt = find_img_info(img, EXIT);
	while (i < curt->count)
	{
		if (x == curt->xpos[i] && y == curt->ypos[i])
			return (1);
		i++;
	}
	return (0);
}

void	mv_player(t_mlx_ptr	*mlx_vars, char	**map, t_img_vars	*img)
{
	if (starting_pt_is_exit(img))
		mv_from_exit(mlx_vars, map, img);
	else
		mv_from_air(mlx_vars, map, img);
}
