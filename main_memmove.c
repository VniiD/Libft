/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_memmove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: v <v@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 23:11:58 by v                 #+#    #+#             */
/*   Updated: 2026/06/02 23:13:01 by v                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n);

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
	size_t	len;

	if (argc < 2 || !argv[1])
		return (ft_putstr("Ex: ./ft_memmove \"SuaString\"\n"), 1);
	buf = malloc(ft_strlen(argv[1]) + 3);
	if (!buf)
		return (ft_putstr("Erro de malloc.\n"), 1);
	buf[0] = '4';
	buf[1] = '2';
	len = -1;
	while (argv[1][++len])
		buf[len + 2] = argv[1][len];
	buf[len + 2] = '\0';
	ft_memmove(buf, buf + 2, len + 1);
	ft_putstr("Resultado memmove: ");
	ft_putstr(buf);
	return (ft_putstr("\n"), free(buf), 0);
}
