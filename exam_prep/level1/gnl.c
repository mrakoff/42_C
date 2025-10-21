
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1024
#endif

char *find_newline(char *str)
{
	char *newline = NULL;
	int i = 0;

	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		newline = &str[i];
	return (newline);
}

void	ft_strcpy(char *dest, char *src)
{
	int i = 0;
	while (dest[i] != '\0' && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
}

char	*ft_strdup(char *str)
{
	int i = 0;
	while (str[i] != '\0')
		i++;
	char *ret = malloc(i);
	ret[i] = '\0';
	ft_strcpy(ret, str);
	return (ret);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int len1 = 0;
	int len2 = 0;
	char *res;

	while (s1[len1] != '\0')
		len1++;
	while (s2[len2] != '\0')
		len2++;
	res = malloc(len1 + len2 + 1);
	int i = 0;
	while (res[i] && s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	int j = 0;
	while (res[i] && s2[j])
	{
		res[i] = s2[j];
		i++;
		j++;
	}
	res[i] = '\0';
	return (res);
}

char    *get_next_line(int fd)
{
	static char buffer[BUFFER_SIZE + 1] = {0};
	static char prev_buffer[BUFFER_SIZE + 1] = {0};
	static char temp[100000];
	char *line;
	int bytes_read = 0;
	char *newline;

	buffer[BUFFER_SIZE] = '\0';
	prev_buffer[BUFFER_SIZE] = '\0';

	if (fd < 0)
		return (NULL);
	while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		int prev_len = strlen(prev_buffer); 
		ft_strcpy(temp, prev_buffer);
		printf("%s\n", temp);

		ft_strcpy(temp + prev_len, buffer);
		line = ft_strdup(temp);
		printf("%s\n", line);

		// check buffer for newline
		newline = find_newline(buffer);
		if (!newline)
		{
			// append the whole buffer
			temp = ft_strjoin(line, buffer);
			line = ft_strdup(temp);
			free(temp);
		}
		else
		{
			// append part of buffer before newline
			int i = 0;
			temp = malloc(sizeof(buffer));
			while (buffer[i] != '\n')
			{
				temp[i] = buffer[i];
				buffer[i] = '\0';
				i++;
			}
			temp[i] = '\0';
			line = ft_strdup(temp);
			free(temp);
			// save the rest of the buffer
			prev_buffer = ft_strdup(newline + 1);
			return (line);
		}
	}
	if (bytes_read < 0 || buffer[0] == '\0')
		return (NULL);
	return (line);
}

int main(void)
{
	int i = 0;
	int fd = open("test.txt", O_RDONLY);

	while (i < 5)
	{
		char *line = get_next_line(fd);
		printf("%s\n", line);
		i++;
	}
	close(fd);
}
