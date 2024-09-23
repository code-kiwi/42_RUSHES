/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_charset.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 01:16:18 by lespenel          #+#    #+#             */
/*   Updated: 2024/08/06 05:53:03 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_mem.h"
#include <stdlib.h>

static size_t		ft_cut(char const *s, char *set, char **strs);
static size_t		ft_count(char const *s, char *set);
static void			free_strs(char **strs);
static int			is_charset(char c, char *set);

char	**ft_split_set(char const *s, char *set)
{
	char	**strs;
	size_t	count;

	count = ft_count(s, set);
	strs = ft_calloc(count + 1, sizeof(char *));
	if (!strs)
		return (NULL);
	if (ft_cut(s, set, strs) == 0)
		return (NULL);
	return (strs);
}

static size_t	ft_cut(char const *s, char *set, char **strs)
{
	size_t	i;
	size_t	count;

	count = 0;
	while (*s)
	{
		i = 0;
		while (is_charset(*s, set) == 0 && s[i])
			i++;
		if (i != 0)
		{
			strs[count] = malloc(sizeof(char) * (i + 1));
			if (!strs[count])
			{
				free_strs(strs);
				return (0);
			}
			ft_strlcpy(strs[count], s, i + 1);
			count++;
			s += i;
		}
		else
			s++;
	}
	return (1);
}

int	is_charset(char c, char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

static void	free_strs(char **strs)
{
	size_t	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

static size_t	ft_count(char const *s, char *set)
{
	size_t	i;
	size_t	count;

	count = 0;
	while (*s)
	{
		i = 0;
		while (is_charset(*s, set) == 0 && s[i])
			i++;
		if (i != 0)
		{
			s += i;
			count++;
		}
		else
			s++;
	}
	return (count);
}
