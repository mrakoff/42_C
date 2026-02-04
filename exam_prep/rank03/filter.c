
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE	1
#endif

void filter(char *str, char *av, int av_len)
{
	int i = 0;
	int j = 0;
	while (str[i] != '\0')
	{
		while (str[i + j] != '\0' && av[j] != '\0' && str[i + j] == av[j])
			j++;
		if (j == av_len)
		{
			j = 0;
			while (j < av_len)
			{
				write (1, "*", 1);
				j++;
			}
			i += j;
		}
		else
		{
			write (1, &str[i], 1);
			i++;
		}
		j = 0;
	}
}

int main(int ac, char **av)
{
	int bytes_read = 0;
	int total_bytes = 0;
	int av_len = strlen(av[1]);
	char buffer[BUFFER_SIZE + 1];
	buffer[BUFFER_SIZE] = '\0';
	char *temp = NULL;
	char *str = NULL;

	if (ac != 2 || !av[1] || av[1][0] == '\0')
		return (perror("Error\n"), 1);
	while ((bytes_read = read(0, buffer, BUFFER_SIZE)) > 0)
	{
		temp = realloc(str, total_bytes + bytes_read + 1); 	// reallocate enough for the whole thing
		temp[total_bytes + bytes_read] = '\0'; 			// null terminate
		str = temp;										// result 
		memmove(str + total_bytes, buffer, bytes_read); // append buffer to the end of result
		total_bytes += bytes_read;	// update total_bytes
		str[total_bytes] = '\0';
	}
	if (bytes_read < 0)
		return (perror("Error"), 1);
	filter(str, av[1], av_len);
	free(str);
	return (0);
}
