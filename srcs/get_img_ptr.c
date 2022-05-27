/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_img_ptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyna <hyna@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 17:02:46 by hyna              #+#    #+#             */
/*   Updated: 2022/05/28 04:41:53 by hyna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	char	*get_imgs_name(int type)
{
	if (type == AIR)
		return ("./imgs/Background.xpm");
	else if (type == WALL)
		return ("./imgs/snowman.xpm");
	else if (type == COLECT)
		return ("./imgs/cookies.xpm");
	else if (type == EXIT)
		return ("./imgs/trapdoor.xpm");
	else
		return ("./imgs/mincho.xpm");
}

void	get_img_ptr(void	*mlx, t_img_vars	*img_vars)
{
	t_img_vars	*curt;
	void		*img;
	int			wid;
	int			ht;
	int			type;

	curt = img_vars;
	while (curt)
	{
		type = curt->type;
		img = mlx_xpm_file_to_image(mlx, get_imgs_name(type), &wid, &ht);
		if (img == NULL)
			put_error_message_exit("get_img_ptr", 1);
		curt->img_ptr = img;
		curt->wid = wid;
		curt->ht = ht;
		curt = curt->next;
	}
}
