/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_img_ptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyna <hyna@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 17:02:46 by hyna              #+#    #+#             */
/*   Updated: 2022/05/27 17:32:56 by hyna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	char	*get_img_name(int	type)
{
	if (type == AIR)
		return ("img/Background.xpm");
	else if (type == WALL)
		return ("img/snowman.xpm");
	else if (type == COLECT)
		return ("img/cookies.xpm");
	else if (type == EXIT)
		return ("img/trapdoor.xpm");
	else
		return ("img/mincho.xpm");
}

static 

void	get_img_ptr(void	*mlx_vars, t_img_vars	*img_vars)
{
	t_img_vars	*curt;
	int			wid;
	int			ht;;
	int			type;

	curt = img_vars;
	while (curt)
	{
		type = curt->type;
		curt->img = mlx_xpm_file_to_image(mlx, get_img_name(type), &wid, &ht);
		curt->width = wid;
		curt->height = ht;
		curt = curt->next;
	}
}