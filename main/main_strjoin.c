/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_strjoin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: v <v@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 23:19:30 by v                 #+#    #+#             */
/*   Updated: 2026/06/02 23:20:26 by v                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2);

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

int	main(int argc, char **argv)
{
	char	*joined_heap;

	if (argc < 3 || !argv[1] || !argv[2])
		return (ft_putstr("Ex: ./ft_strjoin [string1] [string2]\n"), 1);
	joined_heap = ft_strjoin(argv[1], argv[2]);
	if (!joined_heap)
		return (ft_putstr("Erro de hardware: Falha ao alocar RAM.\n"), 1);
	ft_putstr("String 1: \"");
	ft_putstr(argv[1]);
	ft_putstr("\"\nString 2: \"");
	ft_putstr(argv[2]);
	ft_putstr("\"\nResultado da juncao (Heap): \"");
	ft_putstr(joined_heap);
	ft_putstr("\"\n");
	free(joined_heap);
	return (0);
}
