/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: v <v@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 16:13:58 by v                 #+#    #+#             */
/*   Updated: 2026/05/31 22:56:26 by v                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*p1;
	const unsigned char	*p2;
	size_t				i;

	p1 = (const unsigned char *)s1;
	p2 = (const unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (p1[i] != p2[i])
			return (p1[i] - p2[i]);
		i++;
	}
	return (0);
}

/*void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
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

int	main(int argc, char **argv)
{
	int		res;
	size_t	len1;
	size_t	len2;
	size_t	comp_len;

	if (argc < 3 || !argv[1] || !argv[2])
		return (ft_putstr("Ex: ./ft_memcmp \"String1\" \"String2\"\n"), 1);
	len1 = ft_strlen(argv[1]);
	len2 = ft_strlen(argv[2]);
	comp_len = len1;
	if (len2 > len1)
		comp_len = len2;
	res = ft_memcmp(argv[1], argv[2], comp_len);
	ft_putstr("Resultado da comparacao: ");
	if (res == 0)
		ft_putstr("OK (100% Iguais)\n");
	if (res != 0)
		ft_putstr("DIFERENTES (Bits nao batem)\n");
	return (0);
}
*/