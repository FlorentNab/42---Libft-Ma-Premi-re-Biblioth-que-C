/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: FlorentNab <florent.42borntocode@gmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 21:16:20 by flonaben          #+#    #+#             */
/*   Updated: 2024/11/27 21:52:22 by FlorentNab       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//ft_memcpy + gestion des chevauchements (overlapping memory regions)

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int	i;

	if (!dst && !src)
		return (NULL);
	if (dst > src)
	{
		i = (int)len - 1;
		while (i >= 0)
		{
			*(char *)(dst + i) = *(char *)(src + i);
			i--;
		}
	}
	else
	{
		i = 0;
		while (i < (int)len)
		{
			*(char *)(dst + i) = *(char *)(src + i);
			i++;
		}
	}
	return (dst);
}

// #include <stdio.h>
// #include <string.h>

// int main()
// {
// 	char buffer[20] = "Hello, World!";

// 	ft_memmove(buffer + 7, buffer, 5);
// 	buffer[12] = '\0';
// 	printf("Buffer après ft_memmove : %s\n", buffer);

// 	return 0;
// }
