/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_strrchr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: v <v@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 23:33:41 by v                 #+#    #+#             */
/*   Updated: 2026/06/02 23:34:32 by v                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c);


void    ft_putstr(char *str)
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
		return (ft_putstr("Ex: ./ft_strrchr 'String' 'c'\n"), 1);
	res = ft_strrchr(argv[1], argv[2][0]);
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
