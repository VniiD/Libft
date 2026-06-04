/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_putendl_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-alme <vde-alme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 13:46:30 by vde-alme          #+#    #+#             */
/*   Updated: 2026/06/04 14:11:22 by vde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd);

int	ft_aux_atoi(char *str)
{
	int	res;

	if (!str)
		return (0);
	res = 0;	
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	return (res);
}

int	main(int argc, char **argv)
{
	int	canal_fd;

	if (argc < 3 || !argv[1] || !argv[2])
	{
		write(1, "Ex: ./ft_putendl_fd \"[sua frase]\" [fd 1 ou 2]\n", 38);
		return (1);
	}
	canal_fd = ft_aux_atoi(argv[2]);
	if (canal_fd == 2)
	{
		ft_putstr_fd("\033[0;31m[ALERTA DE ERRO]: \033[0m", 2);
		ft_putstr_fd(argv[1], 2);
		ft_putstr_fd("\n", 2);
	}
	else if (canal_fd == 1)
	{
		ft_putstr_fd(argv[1], 1);
		ft_putstr_fd("\n", 1);
	}
	else
	{
		ft_putstr_fd("Erro: Canal invalido. Use 1 ou 2.\n", 2);
		return (1);
	}
	return (0);
}