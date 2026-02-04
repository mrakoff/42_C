#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

char *ft_strdup(char *str)
{
	int len = strlen(str);
	char *res = malloc(len + 1);
	if (!res)
		return (NULL);

	int i = 0;
	while (str[i] != '\0')
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char *ft_strjoin(char *s1, char *s2)
{
	if (!s1 || !s2)
		return (NULL);
	
	int len1 = strlen(s1);
	int len2 = strlen(s2);
	
	char *res = malloc(len1 + len2 + 1);
	if (!res)
		return (NULL);

	int i = 0;
	while (s1[i] != '\0')
	{
		res[i] = s1[i];
		i++;
	}
	int j = 0;
	while (s2[j] != '\0')
	{
		res[i] = s2[j];
		i++;
		j++;
	}
	res[i] = '\0';
	return (res);
}

char *filter(char *av, char *line)
{
	int av_len = strlen(av);
	int line_len = strlen(line);
	int i = 0;
	int j = 0;

	printf("%s\n", line);
	while (i < line_len)
	{
		if (ft_strncmp(line + i, av, av_len) != 0)
			i++;
		else
		{
			while (j <= av_len)
			{
				line[i] = '*';
				i++;
				j++;
			}
		}
	}
	printf("%s\n", line);
}

int main(int ac, char **av)
{
	char	buffer[11];
	int		read_bytes = 0;
	char	*line = NULL;
	char	*temp = NULL;

	if (ac != 2 || av[1][0] == '\0' || !av[1])
		return (1);

	while ((read_bytes = read(0, buffer, 10)) > 0)
	{
		buffer[read_bytes] = '\0';
		if (!line)
			line = ft_strdup(buffer);
		else
		{
			temp = ft_strdup(buffer);
			line = ft_strjoin(line, buffer);
			free(temp);
		}
		if (read_bytes < 0)
		{
			perror("Error: ");
			return (1);
		}
	}
	filter(av[1], line);
	free(line);
	return (0);	
}
