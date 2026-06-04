/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bzero.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-alme <vde-alme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 22:24:00 by v                 #+#    #+#             */
/*   Updated: 2026/06/03 15:21:20 by vde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


void    ft_putstr(char *str)
{
	int	i;
	
	if (!str)
		return ;
	i = 0;
	while (str[i])
	{
		write(0, &str[i], 1);
		i++;
	}
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
	char	buffer[20];
	int		bytes_para_zerar;
	int		i;

	if (argc < 2 || !argv[1])
	{
		ft_putstr("Exemplo de uso: ./exec_bzero [quantidade_de_bytes]\n");
		return (1);
	}
	i = 0;
	while (i < 19)
	{
		buffer[i] = 'A';
		i++;
	}
	buffer[i] = '\0';
	bytes_para_zerar = ft_atoi(argv[1]);
	if (bytes_para_zerar < 0 || bytes_para_zerar > 19)
	{
		ft_putstr("Erro: Quantidade inválida para o tamanho do buffer.\n");
		return (1);
	}
	ft_bzero(buffer, bytes_para_zerar);
	ft_putstr("Operação realizada sem vazamento ou crash na RAM.\n");
	return (0);
}