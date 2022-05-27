/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyna <hyna@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 12:41:30 by hyna              #+#    #+#             */
/*   Updated: 2022/05/27 18:12:53 by hyna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

static int	is_map_file(char	**argv)
{
	int		i;
	char	*str;

	i = 4;
	str = ft_strnstr(argv[1], ".ber", ft_strlen(argv[1]));
	if (str == NULL)
		return (0);
	else if (argv[1] == str)
		return (0);
	else if (str[i] != '\0')
		return (0);
	return (1);
}

void	put_error_message_exit(const char	*str, int error)
{
	if (error != 0)
		perror(str);
	else
		printf("Error! %s\n", str);
	exit(0);
}

int	main(int argc, char	**argv)
{
	t_mlx_ptr	mlx_vars;
	t_map_size	map;
	void		*win;

	if (argc == 1)
		put_error_message_exit("need more arguments.", 0);	
	else if (argc > 2)
		put_error_message_exit("too many arguments.", 0);
	map_processor(argv[1], &map);
	mlx_vars.mlx = mlx_init();
	if (mlx_vars.mlx == NULL)
		put_error_message_exit("So long ", 1);
	win = mlx_new_window(mlx_vars.mlx, map.width * 64, map.height * 64, "so long");
	mlx_vars.win = win;
	if (mlx_vars.win == NULL)
		put_error_message_exit("So long ", 1);
	mlx_loop(mlx_vars.mlx);
	get_img_ptr(mlx_vars.mlx, map.img_vars);
	printf("done!!");
	return (0);
}
