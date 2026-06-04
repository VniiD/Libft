/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_strncmp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: v <v@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 23:29:14 by v                 #+#    #+#             */
/*   Updated: 2026/06/02 23:30:00 by v                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n);

void	ft_putstr(char *str)
{
	if (!str)
		return ;
	while (*str)
	{
		write (1, str, 1);
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
		write (1, "-", 1);
		nb = -nb;
	}
	if (nb > 9)
		ft_putnbr(nb / 10);
	c = ((nb % 10) + '0');
	write(1, &c, 1);
}

int	ft_atoi(char *str) 
{
	int	res;
	int	sgn;

	res = 0;
	sgn = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		sgn = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	return (res * sgn);
}

int	main(int argc, char **argv)
{
	int	res;
	int	limit;

	if (argc < 4 || !argv[1] || !argv[2] || !argv[3])
		return (ft_putstr("Ex: ./ft_strncmp 'string1' 'string2' [numero]\n"), 1);
	limit = ft_atoi(argv[3]);
	if (limit < 0)
		return (ft_putstr("Erro: O limite de bytes deve ser positivo.\n"), 1);
	res = ft_strncmp(argv[1], argv[2], (size_t)limit);
	ft_putstr("Resultado da comparacao: ");
	ft_putnbr(res);
	ft_putstr("\n");
	return (0);
}
