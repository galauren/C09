#include <stdlib.h>

int   is_delimiter(char c, char delimiter)
{
		if (c == delimiter)
				return (1);
		return (0);
}

int   count_words(const char *str, char delimiter)
{
		int   count;
		int   in_word;

		count = 0;
		in_word = 0;
		while (*str)
		{
				if (!is_delimiter(*str, delimiter) && in_word == 0)
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

char  *copy_word(const char *start, const char *end)
{
		char  *word;
		int         i;

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

int   fill_result(const char *str, char delimiter, char **result)
{
		const char  *start;
		int               i;

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

char  **ft_split(const char *str, char delimiter)
{
		char  **result;
		int     words;
		int		nb_to_free;

		if (!str)
				return (0);
		words = count_words(str, delimiter);
		result = malloc(sizeof(char *) * (words + 1));
		if (!result)
				return (0);
		nb_to_free = fill_result(str, delimiter, result);
		if (nb_to_free < 0)
		{
				nb_to_free *= -1;
				while (nb_to_free--)
						free(result[nb_to_free]);
				free(result);
				return (0);
		}
		return (result);
}
/*
#include <stdio.h>
int   main(void)
{
		char  **result;
		int         i;

		result = ft_split("hello world this is C", ' ');
		if (!result)
		{
				printf("Error: Memory allocation failed\n");
				return (1);
		}
		i = 0;
		while (result[i])
		{
				printf("Word %d: %s\n", i, result[i]);
				free(result[i]);
				i++;
		}
		free(result);
		return (0);
}*/
