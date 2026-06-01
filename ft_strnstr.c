/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: v <v@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 21:14:37 by v                 #+#    #+#             */
/*   Updated: 2026/05/31 22:56:02 by v                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (!*little)
		return ((char *)big);
	i = 0;
	while (big[i] && i < len)
	{
		j = 0;
		while (big[i + j] == little[j] && (i + j) < len)
		{
			if (little[j + 1] == '\0')
				return ((char *)&big[i]);
			j++;
		}
		i++;
	}
	return (NULL);
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

int	ft_atoi(const char *str)
{
	size_t	i;
	int		sign;
	int		result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

int	main(int argc, char **argv)
{
	char	*res;
	int		limit;

	if (argc < 4 || !argv[1] || !argv[2] || !argv[3])
		return (ft_putstr
            ("Ex: ./ft_strnstr 'StringGrande' 'Busca' [limite]\n"), 1);
	limit = ft_atoi(argv[3]);
	res = ft_strnstr(argv[1], argv[2], limit);
	ft_putstr("Resultado da busca: ");
	if (res)
	{
		ft_putstr("Encontrado! -> ");
		ft_putstr(res);
	}
	if (!res)
		ft_putstr("Nao encontrado (Fora do limite ou inexistente).");
	ft_putstr("\n");
	return (0);
}
*/