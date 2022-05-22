/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_with_nl.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyna <hyna@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 16:31:14 by hyna              #+#    #+#             */
/*   Updated: 2022/05/22 17:05:15 by hyna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_count(char const	*s, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	if (s[i] && (s[i] == c))
		i++;
	while (s[i])
	{
		while (s[i] && (s[i] != c))
			i++;
		count++;
		while (s[i] && (s[i] == c))
		{
			i++;
			count++;
		}
	}
	return (count);
}

static char	*word_split(char const	*s, char c, int *j)
{
	int	i;

	i = *j;
	if (s[*j] == c)
		return (ft_substr(s, *j, ++(*j) - i));
	while (s[*j] != c)
		(*j)++;
	if (s[*j] == c)
		return (ft_substr(s, *j, ++(*j) - i));
	return (NULL);
}

static void	free_everything(char	**result)
{
	int	i;

	i = 0;
	while (result[i])
	{
		free(result[i]);
		i++;
	}
	free(result);
}

char	**ft_split_with_nl(char const	*s)
{
	char	**result;
	char	c;
	int		j;
	int		k;
	int		count;

	j = 0;
	k = 0;
	c = '\n';
	if (!s)
		return (NULL);
	count = word_count(s, c);
	result = (char **) malloc((count + 1) * sizeof(char *));
	if (!(result))
		return (NULL);
	while (k < count)
	{
		result[k] = word_split(s, c, &j);
		if (!result[k])
		{
			free_everything(result);
			return (NULL);
		}
		k++;
	}
	result[k] = NULL;
	return (result);
}
