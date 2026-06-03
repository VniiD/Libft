/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_isdigit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: v <v@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 22:52:19 by v                 #+#    #+#             */
/*   Updated: 2026/06/02 22:52:30 by v                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c);

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
		return (ft_putstr("Ex: ./ft_isdigit [caractere]\n"), 1);
	result = ft_isdigit((int)argv[1][0]);
	if (result == 1)
		ft_putstr("Resultado: É um digito numerico.\n");
	if (result == 0)
		ft_putstr("Resultado: Não e um digito numerico.\n");
	return (0);
}
