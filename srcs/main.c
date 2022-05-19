/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyna <hyna@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 12:41:30 by hyna              #+#    #+#             */
/*   Updated: 2022/05/19 18:15:05 by hyna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct	s_mlx_ptr {
		void	*mlx;
		void	*win;
}				t_mlx_ptr;

int	exit_game(t_mlx_ptr	*game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}

int	main(void)
{
	t_mlx_ptr	game;
	void		*win;
	void		*img_ptr;
	int			width;
	int			height;
	
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, 841, 841, "Tutorial Window - put image");
	img_ptr = mlx_xpm_file_to_image(game.mlx, "./imgs/mincho.xpm", &width, &height);
	mlx_put_image_to_window(game.mlx, game.win, img_ptr, 0, 0);
	mlx_put_image_to_window(game.mlx, game.win, img_ptr, 64, 64);
	mlx_hook(game.win, 17, 0, &exit_game, &game);
	mlx_loop(game.mlx);
	return (0);
}
