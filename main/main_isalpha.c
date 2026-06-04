/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_isalpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: v <v@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 22:45:54 by v                 #+#    #+#             */
/*   Updated: 2026/06/02 22:46:06 by v                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c);

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
		return (ft_putstr("Ex: ./ft_isalpha [caractere]\n"), 1);
	result = ft_isalpha((int)argv[1][0]);
	if (result == 1)
		ft_putstr("Resultado: E um caractere alfabetico.\n");
	if (result == 0)
		ft_putstr("Resultado: NAO e um caractere alfabetico.\n");
	return (0);
}
