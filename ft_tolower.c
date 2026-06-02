/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: v <v@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 19:58:15 by v                 #+#    #+#             */
/*   Updated: 2026/06/01 20:07:35 by v                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
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
*/