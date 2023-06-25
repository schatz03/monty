#include "monty.h"

/**
 * wc - Helper function to count the number of words in a string
 * @s: String to evaluate
 *
 * Return: Number of words
 */

int wc(char *s)
{
	int word_flag, char_index, word_count;

	word_flag = 0;
	word_count = 0;

	for (char_index = 0; s[char_index] != '\0'; char_index++)
	{
		if (s[char_index] == ' ')
			word_flag = 0;
		else if (word_flag == 0)
		{
			word_flag = 1;
			word_count++;
		}
	}

	return (word_count);
}

/**
 * strtow - Split a string into words
 * @str: String to split
 *
 * Return: Pointer to an array of strings (Success) or NULL (Error
 */

char **strtow(char *str)
{
	char **word_matrix, *tmp;
	int i, matrix_index = 0, str_len = 0;
	int word_count, char_index = 0, word_start, word_end;

	str_len = strlen(str);
	word_count = wc(str);
	if (word_count == 0)
		return (NULL);

	word_matrix = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (word_matrix == NULL)
		return (NULL);

	for (i = 0; i <= str_len; i++)
	{
		if (isspace(str[i]) || str[i] == '\0' || str[i] == '\n')
		{
			if (char_index)
			{
				word_end = i;
				tmp = (char *)malloc(sizeof(char) * (char_index + 1));
				if (tmp == NULL)
					return (NULL);
				while (word_start < word_end)
					*tmp++ = str[word_start++];
				*tmp = '\0';
				word_matrix[matrix_index] = tmp - char_index;
				matrix_index++;
				char_index = 0;
			}
		}
		else if (char_index++ == 0)
			word_start = i;
	}

	word_matrix[matrix_index] = NULL;
	return (word_matrix);
}

/**
 * free_everything - Free arrays of strings
 * @args: Array of strings to free
 *
 * Return: nothing
 */
void free_everything(char **args)
{
	int i;

	if (!args)
		return;

	for (i = 0; args[i]; i++)
		free(args[i]);

	free(args);
}

/**
 * free_instractions - Handles custom memory deallocation
 * @all: Flag indicating what to free
 *
 * Return: nothing
 */

void free_instractions(int all)
{
	if (data.line)
	{
		free(data.line);
		data.line = NULL;
		free_everything(data.words);
		data.words = NULL;
	}

	if (all)
	{
		if (data.stack)
		{
			free_dlistint(data.stack);
			data.stack = NULL;
		}

		if (data.fptr)
		{
			fclose(data.fptr);
			data.fptr = NULL;
		}
	}
}

