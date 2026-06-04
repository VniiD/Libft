/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_strmapi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-alme <vde-alme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 11:44:49 by vde-alme          #+#    #+#             */
/*   Updated: 2026/06/03 13:03:21 by vde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

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

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	ft_trans_astc(unsigned int index, char c)
{
	(void)index;
	(void)c;
	return ('*');
}

char	ft_trans_ind(unsigned int index, char c)
{
	(void)c;
	if (index <= 9)
		return (index + '0');
	return ('X');
}

int	main(int argc, char **argv)
{
	char	*str_origin;
	char	*res_astc;
	char	*res_ind;

	if (argc < 2 || !argv[1])
	{
		ft_putstr("Exemplo de uso: ./teste_explicito [sua_string]\n");
		return (1);
	}
	str_origin = argv[1];
	ft_putstr("- ESTADO INICIAL DA RAM -\n");
	ft_putstr("String original (intacta na Stack): \"");
	ft_putstr(str_origin);
	ft_putstr("\"\n\n");
	res_astc = ft_strmapi(str_origin, ft_trans_astc);
	ft_putstr("- COMPORTAMENTO COM O OPERARDOR * (Asteriscos) -\n");
	ft_putstr("Nova string alocada no Heap:       \"");
	ft_putstr(res_astc);
	ft_putstr("\"\n\n");
	free(res_astc);
	res_ind = ft_strmapi(str_origin, ft_trans_ind);
	ft_putstr("- COMPORTAMENTO COM O OPERADORES NUMERICOS(Índices) -\n");
	ft_putstr("Nova string alocada no Heap:       \"");
	ft_putstr(res_ind);
	ft_putstr("\"\n");
	free(res_ind);

	return (0);
}