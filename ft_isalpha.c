/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: v <v@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 18:17:42 by v                 #+#    #+#             */
/*   Updated: 2026/06/01 18:22:59 by v                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}

/*void	ft_putstr(char *str)
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
*/