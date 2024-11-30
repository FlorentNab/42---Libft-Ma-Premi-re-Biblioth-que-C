/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flonaben <florent.42borntocode@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 21:13:48 by flonaben          #+#    #+#             */
/*   Updated: 2024/11/23 21:21:45 by flonaben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*(char *)(s + i) = 0;
		i++;
	}
}

// #include <stdio.h>

// int	main()
// {
// 	char buffer[10] = "abcdefghi";

// 	ft_bzero(buffer, 5);
// 	printf("Buffer après ft_bzero : %s\n", buffer);

// 	for (int i = 0; i < 10; i++)
// 		printf("buffer[%d] = %d\n", i, buffer[i]);

// 	return 0;
// }
