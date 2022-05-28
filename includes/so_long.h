/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyna <hyna@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 14:49:12 by hyna              #+#    #+#             */
/*   Updated: 2022/05/28 09:44:02 by hyna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>

# define KEY_UP		13
# define KEY_LEFT	0
# define KEY_DOWN	1
# define KEY_RIGHT	2

# define ESC		53
# define CLOSE_WIN	17

# define AIR		48
# define WALL		49
# define COLECT		67
# define EXIT		69
# define PLAYER		80

# define SIZE		32

typedef struct s_img_vars {
	int					type;
	void				*img_ptr;
	int					wid;
	int					ht;
	int					*xpos;
	int					*ypos;
	int					count;
	struct s_img_vars	*next;
}	t_img_vars;

typedef struct s_map_info {
	char				**map;
	int					wid;
	int					ht;
	struct s_img_vars	*img_vars;
}	t_map_info;

typedef struct s_mlx_ptr {
	void				*mlx;
	void				*win;
	struct s_map_info	*map;
}	t_mlx_ptr;

t_img_vars	*find_img_info(t_img_vars	*img, int type);
void		get_img_ptr(void	*mlx, t_img_vars	*img_vars);
void		get_map_info(t_map_info	*map);
void		get_mlx_ptr(t_mlx_ptr	*mlx_vars, t_map_info	*map, char	*title);
void		load_map(t_mlx_ptr	mlx_vars, t_map_info	*map);
void		mv_player(t_mlx_ptr	*mlx_vars, char	**map, t_img_vars	*img);
void		mv_to_air(t_mlx_ptr *mlx_vars, char	**map, t_img_vars	*img);
void		mv_to_colect(t_mlx_ptr *mlx_vars, char	**map, t_img_vars	*img);
void		mv_to_exit(t_mlx_ptr *mlx_vars, char	**map, t_img_vars	*img);
void		put_error_message_exit(const char	*str, int error);
int			get_dest_type(char	**map, t_img_vars	*player);
int			is_map(t_map_info *map);
int			map_processor(char	*map_file, t_map_info	*map);
int			moving_processor(int keycode, t_mlx_ptr	*mlx_vars);

#endif
