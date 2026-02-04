#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int    picoshell(char **cmds[])
{
	int i = 0;
	int pipefd[2];
	int status = 0;
	int in_fd = 0;
	pid_t pid;

	if (!cmds || !cmds[0])
		return (1);

	while (cmds[i])
	{
		if (pipe(pipefd) < 0)
			return (1);

		pid = fork();
		if (pid < 0)
		{
			close(pipefd[0]);
			close(pipefd[1]);
			return (1);
		}

		if (pid == 0)
		{
			if (in_fd != 0)
			{
				dup2(in_fd, STDIN_FILENO);
				close(in_fd);
			}
			if (cmds[i + 1])
			{
				dup2(pipefd[1], STDOUT_FILENO);
				close(pipefd[0]);
				close(pipefd[1]);
			}
			execvp(cmds[i][0], cmds[i]);
			exit(1);
		}
		if (in_fd != 0)
			close(in_fd);
		if (cmds[i + 1])
		{
			close(pipefd[1]);
			in_fd = pipefd[0];
		}
		i++;
	}
	while (wait(&status) > 0)
		if (!WIFEXITED(status) || WEXITSTATUS(status))
			return (1);
	return (0); 
}

int main(void)
{
	// ls | grep "p"
    char *cmd1[] = {"/bin/ls", "../rank04", NULL};
    char *cmd2[] = {"/usr/bin/grep", "p", NULL};
    char **cmds[] = {cmd1, cmd2, NULL};

    int result = picoshell(cmds);
    printf("picoshell returned %d\n", result);

    return 0;
}