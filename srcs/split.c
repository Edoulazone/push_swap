/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 18:34:21 by eschmitz          #+#    #+#             */
/*   Updated: 2025/06/29 17:08:09 by eschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	word_count(char *s, char c)
{
	int	count;
	int	in_word;
	int	i;

	count = 0;
	in_word = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (s[i] == c)
			in_word = 0;
		i++;
	}
	return (count);
}

static char	*extract_word(char *s, char c, int *index)
{
	char	*word;
	int		start;
	int		len;
	int		i;

	while (s[*index] && s[*index] == c)
		(*index)++;
	start = *index;
	while (s[*index] && s[*index] != c)
		(*index)++;
	len = *index - start;
	word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = s[start + i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static void	free_words(char **words, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(words[i]);
		i++;
	}
	free(words);
}

static int	fill_words_array(char **words, char *s, char c, int word_cnt)
{
	int	index;
	int	i;

	index = 0;
	i = 0;
	while (i < word_cnt)
	{
		words[i] = extract_word(s, c, &index);
		if (!words[i])
		{
			free_words(words, i);
			return (0);
		}
		i++;
	}
	words[i] = NULL;
	return (1);
}

char	**ft_split(char *s, char c)
{
	char	**words;
	int		word_cnt;

	if (!s)
		return (NULL);
	word_cnt = word_count(s, c);
	words = malloc(sizeof(char *) * (word_cnt + 1));
	if (!words)
		return (NULL);
	if (!fill_words_array(words, s, c, word_cnt))
		return (NULL);
	return (words);
}
