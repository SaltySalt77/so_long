/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_with_nl.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyna <hyna@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 16:31:14 by hyna              #+#    #+#             */
/*   Updated: 2022/05/22 18:00:49 by hyna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**free_everything(char	**result)
{
	int	i;

	i = 0;
	while (result[i])
	{
		free(result[i]);
		i++;
	}
	free(result);
	return (NULL);
}

char	**ft_split_with_nl(char const	*s)
{
	char	**no_nl_str;
	char	**with_nl_str;
	int		i;
	int		len;

	i = 0;
	len = 0;
	no_nl_str = ft_split(s, '\n');
	if (no_nl_str == NULL)
		return (NULL);
	while (no_nl_str[len] != NULL)
		len++;
	with_nl_str = malloc(sizeof(char *) * (len + 1));
	while (i < len)
	{
		with_nl_str[i] = ft_strjoin(no_nl_str[i], "\n");
		if (with_nl_str[i] == NULL)
			return (free_everything(with_nl_str));
		i++;
	}
	with_nl_str[i] = NULL;
	return (with_nl_str);
}
