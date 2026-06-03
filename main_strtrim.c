/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_strtrim.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: v <v@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 23:35:11 by v                 #+#    #+#             */
/*   Updated: 2026/06/02 23:36:01 by v                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set);

void	ft_putstr(char *str)
{
	if (!str)
		return ;
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	src_len;

	src_len = 0;
	while (src[src_len])
		src_len++;
	if (dstsize == 0)
		return (src_len);
	i = 0;
	while (src[i] != '\0' && i < (dstsize - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}

int	main(int argc, char **argv)
{
	char	*t_heap;

	if (argc < 3 || !argv[1] || !argv[2])
		return (ft_putstr("Ex: ./ft_strtrim [string] [set]\n"), 1);
	t_heap = ft_strtrim(argv[1], argv[2]);
	if (!t_heap)
		return (ft_putstr("Erro de hardware: Falha ao alocar RAM.\n"), 1);
	ft_putstr("String original: \"");
	ft_putstr(argv[1]);
	ft_putstr("\"\nSet de corte:    \"");
	ft_putstr(argv[2]);
	ft_putstr("\"\nResultado (Heap):\"");
	ft_putstr(t_heap);
	ft_putstr("\"\n");
	free(t_heap);
	return (0);
}
