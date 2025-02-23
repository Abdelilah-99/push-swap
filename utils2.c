/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdelilah <abdelilah@student.42.fr>        +#+  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 17:00:00 by abdelilah          #+#    #+#          */
/*   Updated: 2025/02/21 17:00:00 by abdelilah         ###   ########.fr    */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_words(char *str)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && str[i] == ' ')
			i++;
		if (str[i])
			count++;
		while (str[i] && str[i] != ' ')
			i++;
	}
	return (count);
}

static char	*alloc_word(char *str, int len)
{
	char	*word;
	int		j;

	word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	j = 0;
	while (j < len)
	{
		word[j] = str[j];
		j++;
	}
	word[j] = '\0';
	return (word);
}

static char	*get_next_word(char *str, int *i)
{
	char	*word;
	int		len;

	len = 0;
	while (str[*i + len] && str[*i + len] != ' ')
		len++;
	word = alloc_word(str + *i, len);
	*i += len;
	return (word);
}

char	**ft_split(char *str)
{
	char	**words;
	int		word_count;
	int		i;
	int		j;

	if (!str)
		return (NULL);
	word_count = count_words(str);
	words = malloc(sizeof(char *) * (word_count + 1));
	if (!words)
		return (NULL);
	i = 0;
	j = 0;
	while (j < word_count)
	{
		while (str[i] && str[i] == ' ')
			i++;
		words[j] = get_next_word(str, &i);
		if (!words[j])
			return (NULL);
		j++;
	}
	words[j] = NULL;
	return (words);
}
