/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_itoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: v <v@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 20:19:21 by v                 #+#    #+#             */
/*   Updated: 2026/06/02 22:44:15 by v                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n);

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

static int	ft_check_limits(char *str)
{
	long long	res;
	int			sgn;

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
		// Se o acumulador de 64 bits passar dos limites físicos de 32 bits
		if ((sgn == 1 && res > 2147483647) || (sgn == -1 && -res < -2147483648))
			return (1); // Detectou estouro
		str++;
	}
	return (0); // Número seguro
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
	char	*itoa_heap;
	int		number;

	if (argc < 2 || !argv[1])
		return (ft_putstr("Ex: ./ft_itoa [numero_inteiro]\n"), 1);
	
	// Interceptação defensiva na entrada da CLI
	if (ft_check_limits(argv[1]))
		return (ft_putstr("Erro de Input: O numero digitado estoura o limite de um int de 32 bits.\n"), 1);

	number = ft_atoi(argv[1]);
	itoa_heap = ft_itoa(number);
	if (!itoa_heap)
		return (ft_putstr("Erro de hardware: Falha ao alocar na RAM.\n"), 1);
	ft_putstr("Inteiro processador na CPU: ");
	ft_putstr(argv[1]);
	ft_putstr("\nResultado string no Heap:  \"");
	ft_putstr(itoa_heap);
	ft_putstr("\"\n");
	free(itoa_heap);
	return (0);
}