/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyna <hyna@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 12:41:30 by hyna              #+#    #+#             */
/*   Updated: 2022/05/22 21:34:08 by hyna             ###   ########.fr       */
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

	if (argc == 1)
		put_error_message_exit("Error! need more arguments.", 0);	
	else if (argc > 2)
		put_error_message_exit("Error! too many arguments.", 0);
	else if (!is_map_file(argv))
		put_error_message_exit("Error! the arument is not a map.", 0);
	if (!map_processor(argv[1], map))
		put_error_message_exit("Error! map_processor ", 1);
	return (0);
}
