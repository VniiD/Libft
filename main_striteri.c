/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_striteri.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-alme <vde-alme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 16:03:30 by vde-alme          #+#    #+#             */
/*   Updated: 2026/06/03 16:06:30 by vde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*));

void	ft_putstr(char *str)
{
	if (!str)
		return;
	while (*str)
	{
		write (1, str, 1);
		str++;
	}
}

void	f_alterna_box(unsigned int index, char *c)
{
	if (index % 2 == 0)
	{
		if (*c >= 'a' && *c <= 'z')
			*c = *c - 32;
	}
}

int	main(int argc, char **argv)
{
	char	buffer[40];
	int		i;

	if (argc < 2 || !argv[1])
	{
		ft_putstr("Uso: ./exec_striteri [uma_palavra]\n");
		return (1);
	}
	i = 0;
	while (argv[1][i] && i < 39)
	{
		buffer[i] = argv[1][i];
		i++;
	}
	buffer[i] = '\0';
	ft_putstr("Antes da mutacao:  \"");
	ft_putstr(buffer);
	ft_putstr("\"\n");
	ft_striteri(buffer, f_alterna_box);
	ft_putstr("Depois da mutacao: \"");
	ft_putstr(buffer);
	ft_putstr("\"\n");
	return (0);
}