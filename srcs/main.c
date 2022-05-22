/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyna <hyna@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 12:41:30 by hyna              #+#    #+#             */
/*   Updated: 2022/05/20 20:59:35 by hyna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_error_message_exit(const char	*str, int error)
{
	if (error != 0)
		perror(str);
	else
		ft_printf("%s\n", str);
	exit(0);
}

int	main(int argc, char	**argv)
{
	if (argc == 1)
		put_error_message_exit("Error! need more arguments.", 0);	
	else if (argc > 2)
		put_error_message_exit("Error! too many arguments.", 0);
	printf("testing\n");
	return (0);
}
