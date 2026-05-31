/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: v <v@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 19:12:23 by vde-alme          #+#    #+#             */
/*   Updated: 2026/05/31 01:36:07 by v                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    *ft_memset(void *b, int c, size_t len)
{
	unsigned char *ptr;
	
	ptr = (unsigned char *)b;
	while (len > 0)
	{
		*ptr = (unsigned char)c;
		ptr++;
		len--;
	}
	return (b);
}

/*void	ft_putstr(char *str)
{
	while (*str)
	{
		write (1, str, 1);
		str++;
	}
}

int	main(int argc, char **argv)
{
	char	*buffer;
	void	*res;
	int		tamanho;

	if (argc != 3 || argv[1][0] == '\0' || argv[2][0] == '\0')
	{
		ft_putstr("Uso: ./ft_memset insira um caractere e um numero\n");
		return (1);	
	}
	tamanho = argv[2][0] - '0';
	if (tamanho < 0 || tamanho > 5)
	{
		ft_putstr("Erro: O tamanho deve ser entre 0 e 5.\n");
		return (1);
	}
	buffer = (char *)malloc(sizeof(char) * 6);
	if (!buffer)
		return (1);
	res = ft_memset(buffer, argv[1][0], tamanho);
	*(buffer + tamanho) = '\0';
	ft_putstr("Buffer preenchido: ");
	ft_putstr((char *)res);
	ft_putstr("\n");
	free(buffer);
	return (0);
}*/
