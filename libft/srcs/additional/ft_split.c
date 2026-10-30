/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 13:34:18 by htoe              #+#    #+#             */
/*   Updated: 2026/02/14 19:31:17 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_countwords(char const *s, char c)
{
	size_t	wcount;

	wcount = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
			wcount++;
		while (*s && *s != c)
			s++;
	}
	return (wcount);
}

static void	ft_free(char **str, size_t index)
{
	while (index > 0)
		free(str[--index]);
	free(str);
}

static int	ft_copywords(char **arr, char const *s, char c, size_t word_count)
{
	size_t	word;
	size_t	start;
	size_t	end;
	size_t	i;

	start = 0;
	word = 0;
	while (word < word_count)
	{
		while (s[start] && s[start] == c)
			start++;
		end = start;
		while (s[end] && s[end] != c)
			end++;
		arr[word] = (char *)malloc(sizeof(char) * (end - start + 1));
		if (!arr[word])
			return (ft_free(arr, word), 0);
		i = 0;
		while (start < end)
			arr[word][i++] = s[start++];
		arr[word][i] = '\0';
		word++;
	}
	return (1);
}

/*
** ft_split
**
** Purpose:
**     Splits a string into an array of strings using a delimiter character.
**
** Parameters:
**     s - input string
**     c - delimiter character
**
** Returns:
**     A NULL-terminated array of newly allocated strings.
**     Returns NULL if allocation fails or if s is NULL.
**
** Behavior:
**     - Consecutive delimiters are skipped.
**     - Empty words are not created.
**
** Memory:
**     - Allocates memory for the array and each substring.
**     - Caller must free each string and the array itself.
**
** Failure behavior:
**     - Frees all previously allocated substrings before returning NULL.
*/
char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	word_count;

	if (!s)
		return (NULL);
	word_count = ft_countwords(s, c);
	split = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (!split)
		return (NULL);
	split[word_count] = NULL;
	if (!ft_copywords(split, s, c, word_count))
		return (NULL);
	return (split);
}
