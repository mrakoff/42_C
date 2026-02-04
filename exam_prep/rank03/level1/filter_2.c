#include <stdlib.h>
#include <unistd.h>
#define _GNU_SOURCE
#include <string.h>
#include <stdio.h>
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

int	ft_strncmp(char *s1, char *s2, int len)
{
	int i = 0;
	while (i < len && s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	if (i == len)
		return (0);
	else
		return (1);
}

char *filter(char *av, char *line)
{
	int av_len = strlen(av);
	int i = 0;
	int j = 0;

	printf("%s\n", line);
	while (line[i] != '\0')
	{
		if (ft_strncmp(line + i, av, av_len) != 0)
			i++;
		else
		{
			while (j < av_len)
			{
				line[i] = '*';
				i++;
				j++;
			}
		}
	}
	printf("%s\n", line);
}

int	main(int ac, char **av)
{
	if (ac != 2)
		return (1);
	char	buffer[BUFFER_SIZE];
	char	*temp;
	char	*res = NULL;
	char	*pos;
	char	*find = av[1];
	int		find_size = strlen(find);
	int		res_size = 0;
	ssize_t	bytes;

		printf("here");

	while ((bytes = read(0, buffer, BUFFER_SIZE)) > 0)
	{
		printf("here");

		temp = realloc(res, res_size + bytes + 1);
		if (!temp)
			return (free(res), perror("realloc"), 1);
		res = temp;
		memmove(res + res_size, buffer, bytes);
		res_size += bytes;
		res[res_size] = 0;
		printf("here");
	}
	if (bytes < 0)
		return (free(res), perror("read"), 1);
	if (!res)
		return (0);
	filter(find, res);
	// while ((pos = memmem(res, res_size, find, find_size)))
	// 	for (int i = 0; i < find_size; i++)
	// 		pos[i] = 42;
	printf("%s", res);
	free(res);
	return (0);
}
