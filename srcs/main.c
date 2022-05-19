/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyna <hyna@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 12:41:30 by hyna              #+#    #+#             */
/*   Updated: 2022/05/19 16:39:22 by hyna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <math.h>
#include <stdio.h>

int	main(void)
{
	void	*mlx;
	void	*win;
	void	*img_ptr;
	int		width;
	int		height;
	
	mlx = mlx_init();
	win = mlx_new_window(mlx, 841, 841, "Tutorial Window - put image");
	img_ptr = mlx_xpm_file_to_image(mlx, "mincho.xpm", &width, &height);
	//mlx_put_image_to_window(mlx, win, img_ptr, 0, 0);
	//mlx_put_image_to_window(mlx, win, img_ptr, 64, 64);
	mlx_loop(mlx);
	return (0);
}
