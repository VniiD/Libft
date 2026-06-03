/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: v <v@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 12:18:28 by v                 #+#    #+#             */
/*   Updated: 2026/06/02 23:34:11 by v                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	target;
	char			*last_match;

	if (!s)
		return (NULL);
	target = (unsigned char)c;
	last_match = NULL;
	while (*s)
	{
		if ((unsigned char)*s == target)
			last_match = (char *)s;
		s++;
	}
	if (target == '\0')
		return ((char *)s);
	return (last_match);
}
