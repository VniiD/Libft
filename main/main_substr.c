/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_substr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: v <v@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 23:36:32 by v                 #+#    #+#             */
/*   Updated: 2026/06/02 23:38:19 by v                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len);

void	ft_putstr(char *str)
{
	if (!str)
		return ;
	while (*str)
	{
		write (1, str, 1);
		str++;
	}
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
	char	*substring_heap;
	int		start_idx;
	int		alloc_len;

	if (argc < 4 || !argv[1] || !argv[2] || !argv[3])
		return (ft_putstr("Ex: ./ft_substr [string] [start] [len]\n"), 1);
	start_idx = ft_atoi(argv[2]);
	alloc_len = ft_atoi(argv[3]);
	if (start_idx < 0 || alloc_len < 0)
		return (ft_putstr("Erro: Indices nao podem ser negativos.\n"), 1);
	substring_heap = ft_substr(argv[1], (unsigned int)start_idx, (size_t)alloc_len);
	if (!substring_heap)
		return (ft_putstr("Erro de hardware: Falha ao alocar RAM.\n"), 1);
	ft_putstr("String original: \"");
	ft_putstr(argv[1]);
	ft_putstr("\"\nResultado do recorte (Heap): \"");
	ft_putstr(substring_heap);
	ft_putstr("\"\n");
	free(substring_heap);
	return (0);
}
