/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: v <v@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 22:57:23 by v                 #+#    #+#             */
/*   Updated: 2026/05/31 23:06:26 by v                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	target;

	if (!s)
		return (NULL);
	target = (unsigned char)c;
	while (*s)
	{
		if ((unsigned char)*s == target)
			return ((char *)s);
		s++;
	}
	if (target == '\0')
		return ((char *)s);
	return (NULL);
}

/*void	ft_putstr(char *str)
{
	if (!str)
		return ;
	while (*str)
	{
		write (1, str, 1);
		str++;
	}
}

int	main(int argc, char **argv)
{
	char	*res;

	if (argc < 3 || !argv[1] || !argv[2])
		return (ft_putstr("Ex: ./ft_strchr 'String' 'c'\n"), 1);
	res = ft_strchr(argv[1], argv[2][0]);
	ft_putstr("Resultado da busca: ");
	if (res)
	{
		ft_putstr("Encontrado! Resto da string: \"");
		ft_putstr(res);
		ft_putstr("\"\n");
	}
	if (!res)
		ft_putstr("Caractere nao encontrado.\n");
	return (0);
}
*/