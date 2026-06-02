/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: v <v@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 21:17:15 by v                 #+#    #+#             */
/*   Updated: 2026/06/01 21:47:20 by v                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
		unsigned char	*ptr;
		size_t			i;

		ptr = (unsigned char *)s;
		i = 0;
		while (i< n)
		{
			ptr[i] = '\0';
			i++;
		}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	total_size;

	if (nmemb == 0 || size == 0)
	{
		nmemb = 1;
		size = 1;
	}
	if (nmemb > 0 && (size > (size_t)-1 / nmemb))
		return (NULL);
	total_size = nmemb * size;
	ptr = malloc(total_size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, total_size);
	return (ptr);
}

/*void	ft_putstr(char *str)
{
	if (!str)
		return ;
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

void	ft_putnbr(int n)
{
	long	nb;
	char	c;

	nb = n;
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	if (nb > 9)
		ft_putnbr(nb / 10);
	c = ((nb % 10) + '0');
	write(1, &c, 1);
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
	int	*array_heap;
	int	count;
	int	i;

	if (argc < 2 || !argv[1])
		return (ft_putstr("Ex: ./ft_calloc [numero_de_elementos]\n"), 1);
	count = ft_atoi(argv[1]);
	if (count <= 0 || count > 10)
		return (ft_putstr("Erro: Quantidade invalida (insira de 1 a 10).\n"), 1);
	array_heap = (int *)ft_calloc((size_t)count, sizeof(int));
	if (!array_heap)
		return (ft_putstr("Erro de hardware: Falha ao alocar RAM.\n"), 1);
	ft_putstr("Conteudo do Heap apos calloc:\n");
	i = 0;
	while (i < count)
	{
		ft_putstr("Indice [");
		ft_putnbr(i);
		ft_putstr("] = ");
		ft_putnbr(array_heap[i]);
		ft_putstr("\n");
		i++;
	}
	free(array_heap);
	return (0);
}
*/