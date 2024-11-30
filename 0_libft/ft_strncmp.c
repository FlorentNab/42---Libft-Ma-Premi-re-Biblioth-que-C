/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flonaben <florent.42borntocode@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 21:17:42 by flonaben          #+#    #+#             */
/*   Updated: 2024/11/23 21:19:45 by flonaben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	cmp_char(char c1, char c2)
{
	return ((unsigned char)c1 - (unsigned char)c2);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;

	i = 0;
	if (!n)
		return (0);
	while (s1[i] && s2[i] && i < n - 1)
	{
		if (cmp_char(s1[i], s2[i]))
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	if (i < n)
		return (cmp_char(s1[i], s2[i]));
	return (0);
}
/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
	unsigned char s1[10] = "abcdef";
	unsigned char s2[10] = "abc\xfdxx";

	printf("OG : %d\n", strncmp((char *)s1, (char *)s2, 5));
	printf("42 : %d\n", ft_strncmp((char *)s1, (char *)s2, 5));
}
*/
