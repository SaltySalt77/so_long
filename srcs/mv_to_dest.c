/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mv_to_dest.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyna <hyna@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 01:09:30 by hyna              #+#    #+#             */
/*   Updated: 2022/05/28 03:44:39 by hyna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

	//해줘야되는거
	//1. 캐릭터 넣어주기
	//2. 캐릭터 xpos ypos idx 0 없애기
	//if colect : colect count 줄이고 어래이 하나 빼주기
	//if exit : 나갈 수 있는 지 확인하고 니갈 수 있으면 종료

static void	initialize_player_pos(t_img_vars	*img, int	*x, int	*y)
{
	t_img_vars	*curt;

	curt = find_img_info(img, PLAYER);
	*x = curt->xpos[1];
	*y = curt->ypos[1];
	curt->xpos = ft_arr_del_one(curt->xpos, curt->count, 0);
	curt->ypos = ft_arr_del_one(curt->ypos, curt->count, 0);
	if (curt->xpos == NULL || curt->ypos == NULL)
		put_error_message_exit("ft_arr_del_one ", 1);
	curt->count = 1;
	*x *= SIZE;
	*y *= SIZE;
}

static int	find_idx(t_img_vars	*img, int x)
{
	t_img_vars	*curt;
	int	idx;

	idx = 0;
	curt = find_img_info(img, COLECT);
	while (idx < curt->count)
	{
		if (x == curt->xpos[idx])
			return (idx);
		idx++;
	}
	put_error_message_exit("find_idx : out of index", 0);
	return (0);
}

void	mv_to_colect(t_mlx_ptr	*mlx, char	**map, t_img_vars	*img)
{
	t_img_vars	*curt;
	void		*player_img;
	int			x;
	int			y;

	initialize_player_pos(img, &x, &y);
	curt = find_img_info(img, PLAYER);
	player_img = curt->img_ptr;
	curt = find_img_info(img, AIR);
	mlx_put_image_to_window(mlx->mlx, mlx->win, curt->img_ptr, x, y);
	mlx_put_image_to_window(mlx->mlx, mlx->win, player_img, x, y);
	x /= SIZE;
	y /= SIZE;
	curt = find_img_info(img, COLECT);
	x = find_idx(img, x);
	curt->xpos = ft_arr_del_one(curt->xpos, curt->count, x);
	curt->ypos = ft_arr_del_one(curt->ypos, curt->count, y);
	if (curt->xpos == NULL || curt->ypos == NULL)
		put_error_message_exit("ft_arr_del_one ", 1);
	curt->count--;
	map[y][x] = PLAYER;
}

void	mv_to_exit(t_mlx_ptr	*mlx, char	**map, t_img_vars	*img)
{
	t_img_vars	*curt;
	void		*player_img;
	int			x;
	int			y;

	curt = find_img_info(img, COLECT);
	if (curt->count == 0)
		exit(0);
	curt = find_img_info(img, PLAYER);
	player_img = curt->img_ptr;
	initialize_player_pos(img, &x, &y);
	curt = find_img_info(img, AIR);
	mlx_put_image_to_window(mlx->mlx, mlx->win, player_img, x, y);
	map[y / SIZE][x / SIZE] = PLAYER;
}

void	mv_to_air(t_mlx_ptr	*mlx, char	**map, t_img_vars	*img)
{
	t_img_vars	*curt;
	int	x;
	int	y;

	curt = find_img_info(img, PLAYER);
	initialize_player_pos(img, &x, &y);
	mlx_put_image_to_window(mlx->mlx, mlx->win, curt->img_ptr, x, y);
	map[y / SIZE][x / SIZE] = PLAYER;
}
