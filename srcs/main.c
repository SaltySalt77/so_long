/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyna <hyna@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 12:41:30 by hyna              #+#    #+#             */
/*   Updated: 2022/05/20 16:16:22 by hyna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "so_long.h"

int	exit_game(t_mlx_ptr	*game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}

int	move(int keycode, t_img_vars imges)
{
	printf("%d\n", keycode);
	if (keycode == KEY_RIGHT)
	{
		mlx_put_image_to_window(imges.mlx, imges.win, imges.img_ptr, 63, 0);
	}
	return (0);
}

int	main(void)
{
	t_mlx_ptr	game;
	t_img_vars	imges;
	void		*win;
	int			width;
	int			height;
	
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, 128, 128, "Tutorial Window - put image");
	imges.mlx = game.mlx;
	imges.win = game.win;
	imges.img_ptr = mlx_xpm_file_to_image(game.mlx, "./imgs/mincho.xpm", &width, &height);
	mlx_put_image_to_window(game.mlx, game.win, imges.img_ptr, 0, 0);
	mlx_put_image_to_window(game.mlx, game.win, imges.img_ptr, 64, 64);
	mlx_key_hook(game.win, move, &imges);
	mlx_hook(game.win, 17, 0, &exit_game, &game);
	mlx_loop(game.mlx);
	return (0);
}
