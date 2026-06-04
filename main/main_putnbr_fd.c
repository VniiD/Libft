/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_putnbr_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-alme <vde-alme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 16:31:16 by vde-alme          #+#    #+#             */
/*   Updated: 2026/06/04 16:33:15 by vde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <unistd.h>

void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);

int	ft_aux_atoi(char *str)
{
	int	res;
	int	sinal;

	res = 0;
	sinal = 1;
	if (!str)
		return (0);
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sinal = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	return (res * sinal);
}

int	main(int argc, char **argv)
{
	int	number;
	int	canal_fd;

	if (argc < 3 || !argv[1] || !argv[2])
	{
		ft_putstr_fd("\033[1;33mUso: ./exec_putnbr [numero] [fd]\033[0m\n", 1);
		return (1);
	}
	canal_fd = ft_aux_atoi(argv[2]);
	if (canal_fd < 1 || canal_fd > 2)
	{
		ft_putstr_fd("\033[1;31m[ERRO]: Use canal 1 (Stdout) ou 2 (Stderr)\033[0m\n", 2);
		return (1);
	}
	number = ft_aux_atoi(argv[1]);
	if (canal_fd == 2)
		ft_putstr_fd("\033[0;31m[OUTPUT ERRO]: \033[0m", 2);
	ft_putnbr_fd(number, canal_fd);
	ft_putstr_fd("\n", canal_fd);
	return (0);
}
