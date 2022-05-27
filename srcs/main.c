/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyna <hyna@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 12:41:30 by hyna              #+#    #+#             */
/*   Updated: 2022/05/28 05:51:54 by hyna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

static int	is_map_file(int argc, char	**argv)
{
	int		i;
	char	*str;

	i = 4;
	if (argc == 1)
		put_error_message_exit("need one more argument.", 0);
	else if (argc > 2)
		put_error_message_exit("too many arguments.", 0);
	str = ft_strnstr(argv[1], ".ber", ft_strlen(argv[1]));
	if (str == NULL)
		return (0);
	else if (argv[1] == str)
		return (0);
	else if (str[i] != '\0')
		return (0);
	return (1);
}

static int	exit_game(t_mlx_ptr	*mlx_vars)
{
	mlx_destroy_window(mlx_vars->mlx, mlx_vars->win);
	exit(0);
}

void	put_error_message_exit(const char	*str, int error)
{
	printf("Error\n");
	if (error != 0)
		perror(str);
	else
		printf("%s\n", str);
	exit(0);
}

int	main(int argc, char	**argv)
{
	t_mlx_ptr	mlx_vars;
	t_map_size	map;

	if (!is_map_file(argc, argv))
		put_error_message_exit("the argument is not a map file.", 0);
	map_processor(argv[1], &map);
	get_mlx_ptr(&mlx_vars, &map, "so_long");
	get_img_ptr(mlx_vars.mlx, map.img_vars);
	load_map(mlx_vars, &map);
	mlx_key_hook(mlx_vars.win, &moving_processor, &mlx_vars);
	mlx_hook(mlx_vars.win, CLOSE_WIN, 0, &exit_game, &mlx_vars);
	mlx_loop(mlx_vars.mlx);
	return (0);
}
