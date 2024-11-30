/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: FlorentNab <florent.42borntocode@gmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 21:16:56 by flonaben          #+#    #+#             */
/*   Updated: 2024/11/30 22:27:21 by FlorentNab       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	free_tab(char **tab, size_t i)
{
	while (i--)
		free(tab[i]);
	free(tab);
}

static size_t	count_words(char const *s, char c)
{
	size_t	words;

	words = 0;
	while (*s)
	{
		if (*s != c && (*(s + 1) == c || *(s + 1) == '\0'))
			words++;
		s++;
	}
	return (words);
}

static char	*extract_word(char const *s, char c, size_t *index)
{
	size_t	start;	
	size_t	len;
	char	*word;

	start = *index;
	len = 0;
	while (s[start + len] && s[start + len] != c)
		len++;
	word = malloc(len + 1);
	if (!word)
		return (NULL);
	*index = start + len;
	word[len] = '\0';
	while (len--)
		word[len] = s[start + len];
	return (word);
}

char	**ft_split(char const *s, char c)
{
	size_t	words;
	size_t	index;
	size_t	i;
	char	**tab;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	tab = malloc(sizeof(char *) * (words + 1));
	if (!tab)
		return (NULL);
	i = 0;
	index = 0;
	while (i < words)
	{
		while (s[index] == c)
			index++;
		tab[i] = extract_word(s, c, &index);
		if (!tab[i])
			return (free_tab(tab, i), NULL);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

#include <stdio.h>
int	main(void)
{
	char	**result;
	size_t	i;

	// Test case 1: Normal string with spaces as delimiters
	printf("Test 1:\n");
	result = ft_split("Hello world this is 42", ' ');
	i = 0;
	while (result[i])
	{
		printf("Word %zu: %s\n", i, result[i]);
		free(result[i]);
		i++;
	}
	free(result);

	// Test case 2: Multiple consecutive delimiters
	printf("\nTest 2:\n");
	result = ft_split("Split,,,this,,string", ',');
	i = 0;
	while (result[i])
	{
		printf("Word %zu: %s\n", i, result[i]);
		free(result[i]);
		i++;
	}
	free(result);

	// Test case 3: No delimiters
	printf("\nTest 3:\n");
	result = ft_split("NoDelimitersHere", ',');
	i = 0;
	while (result[i])
	{
		printf("Word %zu: %s\n", i, result[i]);
		free(result[i]);
		i++;
	}
	free(result);

	// Test case 4: Empty string
	printf("\nTest 4:\n");
	result = ft_split("", ',');
	if (!result || !result[0])
		printf("Result is empty.\n");
	free(result);

	// Test case 5: String with only delimiters
	printf("\nTest 5:\n");
	result = ft_split(",,,", ',');
	if (!result || !result[0])
		printf("Result is empty.\n");
	free(result);

	// Test case 6: String with delimiters at start and end
	printf("\nTest 6:\n");
	result = ft_split(",start and end,", ',');
	i = 0;
	while (result[i])
	{
		printf("Word %zu: %s\n", i, result[i]);
		free(result[i]);
		i++;
	}
	free(result);

	return (0);
}
