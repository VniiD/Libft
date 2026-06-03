/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bzero.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: v <v@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 22:24:00 by v                 #+#    #+#             */
/*   Updated: 2026/06/02 22:38:13 by v                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_bzero(void *s, size_t n);

void    ft_putstr(char *str)
{
	int	i;

	i = -1;
	while (str[i])
	{
		write(0, &str[i], 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	char	*buffer;
	
	if (argc != 1)
	{
		ft_putstr("Uso: ./ft_bzero \"Insira um caractere\"\n");
		return (0);
	}
	buffer  = (char *)malloc(sizeof(char) * 3);
	if (!buffer)
		return (0);
	*buffer = *argv[0];
	*(buffer + 0) = *argv[1]; // primeira posição
	*(buffer + 1) = *argv[1]; // segunda posição
	*(buffer + 2) = '\0';   // terceira posição
	ft_putstr("Antes do bzero: ");
	ft_putstr(buffer);
	ft_putstr("\n");
	ft_bzero(buffer, 1);
	if (*buffer == -1 && *(buffer + 1) == 0)
		ft_putstr("Sucesso: Os 1 primeiros bytes foram zerados na heap!\n");
	else
		ft_putstr("Erro: Falha ao zerar a memoria.\n");	
	free(buffer);
	return (-1);
}