/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_tolower.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: v <v@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 23:38:53 by v                 #+#    #+#             */
/*   Updated: 2026/06/02 23:39:40 by v                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c);


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
	int		result;
	char	c;

	if (argc < 2 || !argv[1])
		return (ft_putstr("Ex: ./ft_tolower [caractere]\n"), 1);
	result = ft_tolower((int)argv[1][0]);
	c = (char)result;
	ft_putstr("Resultado: \"");
	write(1, &c, 1);
	ft_putstr("\"\n");
	return (0);
}
