/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_mlx_ptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyna <hyna@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 20:23:57 by hyna              #+#    #+#             */
/*   Updated: 2022/05/28 09:38:09 by hyna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_mlx_ptr(t_mlx_ptr	*mlx_vars, t_map_info	*map, char	*title)
{
	int	wid;
	int	ht;

	wid = SIZE * map->wid;
	ht = SIZE * map->ht;
	mlx_vars->mlx = mlx_init();
	if (mlx_vars->mlx == NULL)
		put_error_message_exit("get_mlx_ptr ", 1);
	mlx_vars->win = mlx_new_window(mlx_vars->mlx, wid, ht, title);
	if (mlx_vars->win == NULL)
		put_error_message_exit("get_mlx_ptr ", 1);
	mlx_vars->map = map;
}
