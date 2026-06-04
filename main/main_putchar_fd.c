/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_putchar_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-alme <vde-alme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 16:45:10 by vde-alme          #+#    #+#             */
/*   Updated: 2026/06/03 16:54:29 by vde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	fd_putchar_fd(char c, int fd);

void	ft_putstr(char *str)
{
	int	i;

	if (!str)
		return ;
	i = 0;
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

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
	char	caractere;
	int		canal_fd;

	if (argc < 3 || !argv[1] || !argv[2])
	{
		ft_putstr("Uso: ./exec_putchar [caractere] [file_descriptor]\n");
		ft_putstr("Canais: 1 (Stdout) ou 2 (Stderr)\n");
		return (1);
	}
	caractere = argv[1][0];
	canal_fd = ft_aux_atoi(argv[2]);
	if (canal_fd < 1 || canal_fd > 2)
	{
		ft_putstr("Erro: Use apenas 1 (Stdout) ou 2 (Stderr).\n");
		return (1);
	}
	ft_putchar_fd(caractere, canal_fd);
	ft_putchar_fd('\n', canal_fd);
	return (0);
}
