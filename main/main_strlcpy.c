/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_strlcpy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: v <v@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 23:25:40 by v                 #+#    #+#             */
/*   Updated: 2026/06/02 23:26:27 by v                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);


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

int main(int argc, char **argv)
{
	char	*buffer_heap;
	int		limit;
	size_t	retorn;

	if (argc < 3 || !argv[1] || !argv[2])
		return (ft_putstr("Ex: ./ft_strlcpy 'Origem' [tamanho_dst]\n"), 1);
	limit = ft_atoi(argv[2]);
	if (limit < 0 || limit > 15)
		return (ft_putstr("Erro: Tamanho invalido.\n"), 1);
	buffer_heap = (char *)malloc(15 * sizeof(char));
	if (!buffer_heap)
		return (ft_putstr("Erro de hardware: Falha ao alocar RAM.\n"), 1);
	retorn = ft_strlcpy(buffer_heap, argv[1], (size_t)limit);
	ft_putstr("Buffer no Heap apos a copia: \"");
	ft_putstr(buffer_heap);
	ft_putstr("\"\nRetorno: ");
	ft_putnbr((int)retorn);
	ft_putstr("\n");
	free(buffer_heap); 
	return (0);
}
