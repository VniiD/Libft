/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: v <v@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 16:04:21 by v                 #+#    #+#             */
/*   Updated: 2026/06/01 16:57:16 by v                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	dst_len = 0;
	while (dst_len < dstsize && dst[dst_len] != '\0')
		dst_len++;
	src_len = 0;
	while (src[src_len] != '\0')
		src_len++;
	if (dst_len == dstsize)
		return (dstsize + src_len);
	i = 0;
	while (src[i] != '\0' && (dst_len + i + 1) < dstsize)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
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

void	ft_putnbr(int n)
{
	long	nb;
	char	c;

	nb = n;
	if (nb < 0)
	{
		write (1, "-", 1);
		nb = -nb;
	}
	if (nb > 9)
		ft_putnbr(nb / 10);
	c = ((nb % 10) + '0');
	write(1, &c, 1);
}

int	ft_atoi(char *str) 
{
	int	res;
	int	sgn;

	res = 0;
	sgn = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		sgn = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	return (res * sgn);
}

int	main(int argc, char **argv)
{
	char	*buffer_heap;
	int		limit;
	size_t	retorn;
	int		i;

	if (argc < 4 || !argv[1] || !argv[2] || !argv[3])
		return (ft_putstr("Ex: ./ft_strlcat 'Init' 'Orig' [Number]\n"), 1);
	limit = ft_atoi(argv[3]);
	if (limit < 0 || limit > 15)
		return (ft_putstr("Erro: Tamanho deve ser entre 0 e 15.\n"), 1);
	buffer_heap = (char *)malloc(15 * sizeof(char));
	if (!buffer_heap)
		return (ft_putstr("Erro de hardware: Falha ao alocar RAM.\n"), 1);
	
	i = 0;
	while (argv[1][i] != '\0' && i < 14)
	{
		buffer_heap[i] = argv[1][i];
		i++;
	}
	buffer_heap[i] = '\0';

	retorn = ft_strlcat(buffer_heap, argv[2], (size_t)limit);
	ft_putstr("Buffer no Heap apos a concatenacao: \"");
	ft_putstr(buffer_heap);
	ft_putstr("\"\nEspaço esperado: ");
	ft_putnbr((int)retorn);
	ft_putstr("\n");
	free(buffer_heap);
	return (0);
}
*/