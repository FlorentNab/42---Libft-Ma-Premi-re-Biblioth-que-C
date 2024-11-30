/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: FlorentNab <florent.42borntocode@gmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 21:16:24 by flonaben          #+#    #+#             */
/*   Updated: 2024/11/25 22:58:05 by FlorentNab       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		*(unsigned char *)(b + i) = (unsigned char) c;
		i++;
	}
	return (b);
}

// #include <stdio.h>
// #include <string.h>

// int	main()
// {
// 	char buffer[10] = "abcdefghi";

// 	ft_memset(buffer, 'x', 5);
// 	printf("Buffer après memset : %s\n", buffer);

// 	return 0;
// }
