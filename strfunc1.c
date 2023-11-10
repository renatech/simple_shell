#include "main.h"

/**
 * words_to_count - counts the number of words of a string.
 * @s: string to be evaluated.
 * @d: delimeter.
 * Return: words_to_count.
 */


int words_to_count(char *s, char *d)
{
	int i, wc = 0, l = 0, j;

	for (i = 0; s[i] != '\0'; ++i)
		for (j = 0; d[j] != '\0'; ++j)
		{
			if (s[i] != d[j] && l == 0)
			{
				l = 1;
				wc++;
			}

			else if (s[i] == d[j] && l != 0)
				l = 0;

		}
	return (wc);
}
/**
 * each_word - retrieves word a string.
 * @s: word from string.
 * Return: pointer to word.
 */


char *each_word(char *s)
{
	char *w;
	int i;


	for (i = 0; s[i] != '\0'; ++i)
		;

	w = (char *)malloc(sizeof(char) * (i + 1));

	if (w)
	{
		for (i = 0; s[i] != '\0'; ++i)
			w[i] = s[i];
		w[i] = '\0';
	}

	return (w);
}

/**
 * _strtok - splits string into words.
 * @str: string passed.
 * @d: delimeter.
 * Return: Null if failed. Otherwise return pointer to pointer.
 */

char **_strtok(char *str, char *d)
{
	char **arr;
	int i, l = 0, wc, j;

	if (str == NULL)
		return (NULL);

	wc = words_to_count(str, d);
	if (wc == 0)
		return (NULL);

	arr = (char **)malloc(sizeof(char *) * (wc + 1));

	if (arr)
	{
		for (i = 0; i <= wc; ++i)
			arr[i] = NULL;
	}

	wc = 0;
	i = 0;

	for (i = 0; str[i] != '\0'; i++)
		for (j = 0; d[j] != '\0'; j++)
			if (str[i] != d[j] && l == 0)
			{
				*(arr + wc) = each_word((str + i));

				if (arr[wc] == 0)
				{
					for (i = 0; i <= wc; ++i)
						free(arr[wc]);
					free(arr);
					return (NULL);
				}
				wc++;
				l = 1;
			}
			else if (str[i] == d[j] && l != 0)
				l = 0;
	return (arr);
}
