/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyna <hyna@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 14:49:12 by hyna              #+#    #+#             */
/*   Updated: 2022/05/22 15:43:46 by hyna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
//need to change into wasd keys
# define KEY_LEFT	123
# define KEY_RIGHT	124
# define KEY_DOWN	125
# define KEY_UP		126

# define CLOSE_WIN	17

# define AIR		0
# define WALL		1
# define COLECT		67
# define EXIT		69
# define PLAYER		80

typedef struct s_mlx_ptr {
	void	*mlx;
	void	*win;
}	t_mlx_ptr;

typedef struct s_img_vars {
	int					type;
	void				*img_ptr;
	int					width;
	int					height;
	int					*xpos;
	int					*ypos;
	struct s_img_vars	*next;
}	t_img_vars;

typedef struct s_map_size {
	char				**map;
	int					width;
	int					height;
	struct s_img_vars	*img_vars;
}	t_map_size;

void	put_error_message_exit(const char	*str, int error);
int		map_processor(char	*map_file, t_map_size	map);

#endif
