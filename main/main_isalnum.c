/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_isalnum.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: v <v@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 22:35:30 by v                 #+#    #+#             */
/*   Updated: 2026/06/02 22:35:38 by v                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c);

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

int	main(int argc, char **argv)
{
	int	result;

	if (argc < 2 || !argv[1])
		return (ft_putstr("Ex: ./ft_isalnum [caractere]\n"), 1);
	result = ft_isalnum((int)argv[1][0]);
	if (result == 1)
		ft_putstr("Resultado: É um caractere alfanumerico.\n");
	if (result == 0)
		ft_putstr("Resultado: NÃO e um caractere alfanumerico.\n");
	return (0);
}
