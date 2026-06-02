/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: v <v@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 19:30:20 by v                 #+#    #+#             */
/*   Updated: 2026/06/01 19:53:00 by v                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
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
	int	result;
	char	c;

	if (argc < 2 || !argv[1])
		return (ft_putstr("Ex: ./ft_toupper [caractere]\n"), 1);
	result = ft_toupper((int)argv[1][0]);
	c = (char)result;
	ft_putstr("Resultado: \"");
	write(1, &c, 1);
	ft_putstr("\"\n");
	return (0);
}
*/