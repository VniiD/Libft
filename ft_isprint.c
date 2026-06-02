/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: v <v@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 18:48:19 by v                 #+#    #+#             */
/*   Updated: 2026/06/01 18:51:31 by v                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
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
		return (ft_putstr("Ex: ./ft_isprint [caractere]\n"), 1);
	result = ft_isprint((int)argv[1][0]);
	if (result == 1)
		ft_putstr("Resultado: E um caractere imprimivel.\n");
	if (result == 0)
		ft_putstr("Resultado: NAO e um caractere imprimivel.\n");
	return (0);
}
*/