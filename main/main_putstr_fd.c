/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_putstr_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-alme <vde-alme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 17:14:10 by vde-alme          #+#    #+#             */
/*   Updated: 2026/06/03 17:16:27 by vde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd);

int	ft_aux_atoi(char *str)
{
	int	res;

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
		ft_putstr_fd("Uso: ./exec_putstr \"[sua frase]\" [file_descriptor]\n", 1);
		return (1);
	}
	canal_fd = ft_aux_atoi(argv[2]);
	if (canal_fd < 1 || canal_fd > 2)
	{
		ft_putstr_fd("Erro: Use apenas 1 (Stdout) ou 2 (Stderr).\n", 2);
		return (1);
	}
	ft_putstr_fd(argv[1], canal_fd);
	ft_putstr_fd("\n", canal_fd);
	return (0);
}