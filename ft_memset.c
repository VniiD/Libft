/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-alme <vde-alme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 19:12:23 by vde-alme          #+#    #+#             */
/*   Updated: 2026/05/29 20:02:19 by vde-alme         ###   ########.fr       */
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
void	ft_putstr(char *str)
{
	int	i;
	
	i = 0;
	while (str[i++])
		write (1, &str[i], 1);
}

int	main(int argc, char **argv)
{
	char	*buffer;
	void	*res;

	if (argc != 3 || argv[1][0] == '\0' || argv[2][0] == '\0')
	{
	ft_putstr("Uso: ./ft_memset \"insira um caratere\ "numero"\n");
	return (1);	
	}
	buffer = (char *)malloc(sizeof(char) * 6); /* Libero 6 Bytes na memoria heap para os testes*/
	if (!buffer)
		return (1);
	res = ft_memset(buffer, argv[1][0], argv[2][0] - '0');
	*(buffer + 5) = '\0';
	ft_putstr("Buffer preenchido: ");
	ft_putstr((char *)res);
	ft_putstr("\n");
	free(buffer);
	return (0);
}