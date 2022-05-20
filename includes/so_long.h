/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyna <hyna@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 14:49:12 by hyna              #+#    #+#             */
/*   Updated: 2022/05/20 16:17:12 by hyna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <libft.h>
# include <get_next_line.h>

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

typedef struct s_map_size {
	char	**map;
	int		width;
	int		height;
	void	*img_vars;
}	t_map_size;

typedef struct s_img_vars {
	int		type;
	void	*img_ptr;
	int		width;
	int		height;
	void	*next;
}	t_img_vars;

#endif
