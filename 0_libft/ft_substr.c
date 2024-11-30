/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: FlorentNab <florent.42borntocode@gmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 21:18:00 by flonaben          #+#    #+#             */
/*   Updated: 2024/11/25 23:13:01 by FlorentNab       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*new;
	unsigned int	i;

	if (start >= ft_strlen(s))
		len = 0;
	else if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	new = malloc(sizeof(char) * (len + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (start + i < ft_strlen(s) && i < len)
	{
		new[i] = s[start + i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// size_t	ft_strlen(const char *s)
// {
// 	size_t	len = 0;
// 	while (s[len])
// 		len++;
// 	return (len);
// }

// int	main(void)
// {
// 	const char	*str = "Hello, world!";
// 	unsigned int start = 7;
// 	size_t len = 5;

// 	char *substring = ft_substr(str, start, len);
// 	if (substring)
// 	{
// 		printf("Sous-chaîne extraite : '%s'\n", substring);
// 		free(substring);
// 	}
// 	else
// 	{
// 		printf("Échec de l'allocation mémoire.\n");
// 	}

// 	printf("Cas start hors de portée : '%s'\n", ft_substr(str, 20, 5));
// 	printf("Cas len trop long : '%s'\n", ft_substr(str, 0, 50));

// 	return (0);
// }
