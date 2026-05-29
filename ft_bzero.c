/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-alme <vde-alme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 14:11:06 by vde-alme          #+#    #+#             */
/*   Updated: 2026/05/29 19:52:08 by vde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_bzero(void *s, size_t n)
{
	unsigned char *ptr;

	ptr = (unsigned char *)s;
	while (n--)
		*ptr++ = '\0';
}

/*void    ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	char	*buffer;
	
	if (argc != 2)
	{
		ft_putstr("Uso: ./ft_bzero \"Insira um caractere\"\n");
		return (1);
	}
	buffer  = (char *)malloc(sizeof(char) * 4);
	if (!buffer)
		return (1);
	*buffer = *argv[1];
	*(buffer + 1) = *argv[1]; // primeira posição
	*(buffer + 2) = *argv[1]; // segunda posição
	*(buffer + 3) = '\0';   // terceira posição
	ft_putstr("Antes do bzero: ");
	ft_putstr(buffer);
	ft_putstr("\n");
	ft_bzero(buffer, 2);
	if (*buffer == 0 && *(buffer + 1) == 0)
		ft_putstr("Sucesso: Os 2 primeiros bytes foram zerados na heap!\n");
	else
		ft_putstr("Erro: Falha ao zerar a memoria.\n");	
	free(buffer);
	return (0);
}
*/