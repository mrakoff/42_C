#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void swap(char *a, char *b)
{
	char temp = *a;
	
	*a = *b;
	*b = temp;
}

void sort(char *str)
{
	int i = 0;

	while (str[i] && str[i + 1])
	{
		if (str[i] > str[i + 1])
		{
			swap(&str[i], &str[i + 1]);
			i = 0;
		}
		else
			i++;
	}
}

int	ft_strchr(char *str, char c)
{
	int i = 0;

	while (str[i] && str[i] != c)
		i++;
	if (str[i] == '\0')
		return (0);
	return (1);
}

void backtrack(char *str, char *result, int len, int current_len)
{
	// basecase
	if (current_len == len) // all of the letters are used?
	{
		write(1, result, len);
		write(1, "\n", 1);
		return ;
	}
	int i = 0;
	while (i < len)
	{
		if (ft_strchr(result, str[i]) == 0) // not used yet
		{
			result[current_len] = str[i];
			backtrack(str, result, len, current_len + 1); // checks if we reached the end of the word
			result[current_len] = '\0';
		}
		i++;
	}
}

int main(int ac, char **av)
{
	int len = 0;
	char *str = av[1];
	char *result;

	if (ac != 2)
		return (1);

	while (str[len])
		len++;
	sort(str);
	result = malloc(len + 1);
	result[len] = '\0';
	backtrack(str, result, len, 0);
}
