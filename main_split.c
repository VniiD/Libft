/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: v <v@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 22:39:51 by v                 #+#    #+#             */
/*   Updated: 2026/06/02 22:40:24 by v                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_split(char const *s, char c);

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

void	ft_putnbr(int n)
{
	long	nb;
	char	c;

	nb = n;
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	if (nb > 9)
		ft_putnbr(nb / 10);
	c = ((nb % 10) + '0');
	write(1, &c, 1);
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
	char	**matrix_heap;
	int		i;

	if (argc < 3 || !argv[1] || !argv[2])
		return (ft_putstr("Ex: ./ft_split [string] [char_delimitador]\n"), 1);
	matrix_heap = ft_split(argv[1], argv[2][0]);
	if (!matrix_heap)
		return (ft_putstr("Erro de hardware: Falha ao alocar a matriz.\n"), 1);
	ft_putstr("Matriz fragmentada no Heap:\n");
	i = 0;
	while (matrix_heap[i] != NULL)
	{
		ft_putstr("Indice [");
		ft_putnbr(i);
		ft_putstr("]: \"");
		ft_putstr(matrix_heap[i]);
		ft_putstr("\"\n");
		free(matrix_heap[i]);
		i++;
	}
	free(matrix_heap);
	return (0);
}
