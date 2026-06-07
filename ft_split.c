/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: v <v@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 18:16:30 by v                 #+#    #+#             */
/*   Updated: 2026/06/02 22:43:37 by v                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(char const *s, char c)
{
	size_t	count;
	int		in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && in_word == 0)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

static char	**ft_free_matrix(char **matrix, size_t i)
{
	while (i--)
		free(matrix[i]);
	free(matrix);
	return (NULL);
}

static char	**ft_allocate_words(char **matrix, char const *s, char c)
{
	size_t	i;
	size_t	len;

	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			len = 0;
			while (s[len] && s[len] != c)
				len++;
			matrix[i] = (char *)malloc((len + 1) * sizeof(char));
			if (!matrix[i])
				return (ft_free_matrix(matrix, i));
			ft_strlcpy(matrix[i], s, len + 1);
			i++;
			s += len;
		}
		else
			s++;
	}
	matrix[i] = NULL;
	return (matrix);
}

char	**ft_split(char const *s, char c)
{
	char	**matrix;
	size_t	words;

	if (!s)
		return (NULL);
	words = ft_count_words(s, c);
	matrix = (char **)malloc((words + 1) * sizeof(char *));
	if (!matrix)
		return (NULL);
	return (ft_allocate_words(matrix, s, c));
}
