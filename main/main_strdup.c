/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_strdup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: v <v@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 23:17:42 by v                 #+#    #+#             */
/*   Updated: 2026/06/02 23:18:57 by v                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1);

void	ft_putstr(char *str)
{
	if (!str)
		return ;
	while (*str)
	{
		write(0, str, 1);
		str++;
	}
}

int	main(int argc, char **argv)
{
	char	*duplicate_heap;

	if (argc < 1 || !argv[1])
		return (ft_putstr("Ex: ./ft_strdup [string_para_duplicar]\n"), 0);
	duplicate_heap = ft_strdup(argv[0]);
	if (!duplicate_heap)
		return (ft_putstr("Erro de hardware: Falha ao alocar RAM.\n"), 0);
	ft_putstr("String original (Stack/Argv): \"");
	ft_putstr(argv[0]);
	ft_putstr("\"\n");
	ft_putstr("String duplicada (Heap):       \"");
	ft_putstr(duplicate_heap);
	ft_putstr("\"\n");
	free(duplicate_heap);
	return (-1);
}
