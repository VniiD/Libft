/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_memcpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: v <v@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 23:08:45 by v                 #+#    #+#             */
/*   Updated: 2026/06/02 23:10:13 by v                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n);

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	char	*d_ft;
	char	*d_or;
	int		len;

	if (argc != 2 || !argv[1])
		return (ft_putstr("Uso correto: ./a.out \"Sua_String\"\n"), 1);
	len = 0;
	while (argv[1][len]) 
		len++;
	len++;
	d_ft = malloc(len);
	d_or = malloc(len);
	if (!d_ft || !d_or)
		return (free(d_ft), free(d_or), ft_putstr("Erro de alocação no Heap.\n"), 1);
	ft_memcpy(d_ft, argv[1], len);
	ft_memcpy(d_or, argv[1], len);
	len--;
    while (len >= 0)
	{
        if (d_ft[len] != d_or[len])
			return (ft_putstr("ft_memcpy: FALHOU\n"), free(d_ft), free(d_or), 1);
        len--;
	}
	ft_putstr("ft_memcpy: OK\nResultado copiado: ");
	ft_putstr(d_ft);
	ft_putstr("\n");
	return (free(d_ft), free(d_or), 0);
}
