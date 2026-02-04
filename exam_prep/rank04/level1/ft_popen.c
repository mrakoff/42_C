
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

int ft_popen(const char *file, char *const argv[], char type)
{
	int pipefd[2];
	pid_t pid;

	if (!file || !argv || (type != 'r' && type != 'w'))
		return (-1);

	if (pipe(pipefd) < 0)
		return (-1);

	pid = fork();
	if (pid < 0)
	{
		close(pipefd[0]);
		close(pipefd[1]);
		return (-1);
	}

	if (pid == 0)
	{
		if (type == 'r')
		{
			if (dup2(pipefd[1], STDOUT_FILENO))
			{
				close(pipefd[0]);
				close(pipefd[1]);
			}
		}
		else
		{
			if (dup2(pipefd[0], STDIN_FILENO))
			{
				close(pipefd[0]);
				close(pipefd[1]);
			}
		}

		close(pipefd[0]);
		close(pipefd[1]);

		execvp(file, argv);
		exit(1);
	}
	
	if (type == 'r')
	{
		close(pipefd[1]);
		return (pipefd[0]);
	}
	else
	{
		close(pipefd[0]);
		return (pipefd[1]);
	}
}

int main()
{
    int  fd;
	char c;

    fd = ft_popen("ls", (char *const []){"ls", NULL}, 'r');
   	while (read(fd, &c, 1) > 0)
        write(1, &c, 1);
    
	close(fd);
    return (0);
}
