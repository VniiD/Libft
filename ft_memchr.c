/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: v <v@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 00:28:23 by v                 #+#    #+#             */
/*   Updated: 2026/06/02 23:04:32 by v                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*ptr;
	unsigned char		target;

	ptr = (const unsigned char *)s;
	target = (unsigned char)c;
	while (n > 0)
	{
		if (*ptr == target)
			return ((void *)ptr);
		ptr++;
		n--;
	}
	return (NULL);
}
