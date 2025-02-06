/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galauren <galauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 12:33:27 by galauren          #+#    #+#             */
/*   Updated: 2025/01/30 18:41:44 by galauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	is_delimiter(char c, char *delimiters)
{
	int	i;

	i = -1;
	while (delimiters[++i])
		if (c == delimiters[i])
			return (1);
	return (0);
}

int	count_words(const char *str, char *delimiter)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*str)
	{
		if (!is_delimiter(*str, delimiter) && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (is_delimiter(*str, delimiter))
			in_word = 0;
		str++;
	}
	return (count);
}

char	*copy_word(const char *start, const char *end)
{
	char	*word;
	int		i;

	word = malloc(sizeof(char) * (end - start + 1));
	if (!word)
		return (0);
	i = 0;
	while (start < end)
	{
		word[i] = *start;
		start++;
		i++;
	}
	word[i] = '\0';
	return (word);
}

int	fill_result(const char *str, char *delimiter, char **result)
{
	const char	*start;
	int			i;

	i = 0;
	while (*str)
	{
		if (!is_delimiter(*str, delimiter))
		{
			start = str;
			while (*str && !is_delimiter(*str, delimiter))
				str++;
			result[i] = copy_word(start, str);
			if (!result[i])
				return (-i);
			i++;
		}
		else
			str++;
	}
	result[i] = 0;
	return (0);
}

char	**ft_split(const char *str, char *delimiter)
{
	char	**result;
	int		words;

	if (!str)
		return (0);
	words = count_words(str, delimiter);
	result = malloc(sizeof(char *) * (words + 1));
	if (!result)
		return (0);
	fill_result(str, delimiter, result);
	return (result);
}
/*
#include <stdio.h>
int	main(int argc, char **argv)
{
	char	**res;
	char	charset[] = " ;";
	if (argc != 2)
		return (0);
	res = ft_split(argv[1], charset);

	int i = -1;
	while (res[++i])
		printf("%s\n",res[i]);
	return (0);
}*/
