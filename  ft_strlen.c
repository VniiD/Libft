/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    ft_strlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: v <v@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 22:20:21 by v                 #+#    #+#             */
/*   Updated: 2026/05/31 22:56:56 by v                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

    if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

/*void    ft_putstr(char *str)
{
    if (!str)
        return ;
    while (*str)
    {
        write(1, str, 1);
        str++;
    }
}

void	ft_putnbr(int n)
{
	long	nb;
	char	c;

	nb = n;
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
	}
	c = (nb % 10) + '0';
	write(1, &c, 1);
}

int	main(int argc, char **argv)
{
	size_t	len;

	if (argc < 2 || !argv[1])
		return (ft_putstr("Ex: ./ft_strlen 'SuaString' \n"), 1);
	len = ft_strlen(argv[1]);
	if (len == 0)
		ft_putstr("0 (String vazia)");
	if (len > 0)
    {
		ft_putstr("'Valido' | ");
        ft_putstr("Tamanho da string: ");
        ft_putnbr(len);
    }
	ft_putstr("\n");
	return (0);
}
*/