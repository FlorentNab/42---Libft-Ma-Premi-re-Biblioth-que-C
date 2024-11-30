/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flonaben <florent.42borntocode@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 21:16:07 by flonaben          #+#    #+#             */
/*   Updated: 2024/11/21 22:15:33 by flonaben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;

	i = 0;
	while (i < n)
	{
		if (*(unsigned char *)(s1 + i) != *(unsigned char *)(s2 + i))
			return (*(unsigned char *)(s1 + i) - *(unsigned char *)(s2 + i));
		i++;
	}
	return (0);
}
// #include <stdio.h>

// int main()
// {
//     char s1[] = "abcdef";
//     char s2[] = "abcxef";
//     char s3[] = "abcdef";

//     printf("Comparaison s1 et s2 : %d\n", ft_memcmp(s1, s2, 6));
//     printf("Comparaison s1 et s3 : %d\n", ft_memcmp(s1, s3, 6));

//     return 0;
// }
