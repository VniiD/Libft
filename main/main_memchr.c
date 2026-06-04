/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_memchr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: v <v@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 23:01:54 by v                 #+#    #+#             */
/*   Updated: 2026/06/02 23:04:26 by v                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n);

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*dest;
	size_t	len;
	size_t	i;

	len = ft_strlen(s1);
	dest = malloc(len + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (i <= len)
	{
		dest[i] = s1[i];
		i++;
	}
	return (dest);
}

int	main(int argc, char **argv)
{
	char	*buf;
	char	*res;
	char	to_find;

	if (argc < 2 || !argv[1])
		return (
        ft_putstr("Ex: ./ft_memchr \"Insira uma string e um [char]\n"), 1);
	to_find = '\0';
	if (argc >= 3 && argv[2])
		to_find = argv[2][0];
	buf = ft_strdup(argv[1]);
	if (!buf)
		return (ft_putstr("Erro de malloc.\n"), 1);
	res = ft_memchr(buf, to_find, ft_strlen(buf) + 1);
	if (res)
	{
		ft_putstr("ft_memchr: OK\n");
		ft_putstr(res);
	}
	if (!res)
		ft_putstr("ft_memchr: NULL");
	return (ft_putstr("\n"), free(buf), 0);
}
