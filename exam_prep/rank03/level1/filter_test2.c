#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>

#define BUFFER_SIZE 4096

int main(int argc, char **argv)
{
    if (argc != 2 || argv[1][0] == '\0')
        return (1);

    char *pattern = argv[1];
    size_t pat_len = strlen(pattern);
    char buffer[BUFFER_SIZE];
    ssize_t bytes_read;

    // store partial match across buffer reads
    char *stash = NULL;
    size_t stash_len = 0;

    while ((bytes_read = read(STDIN_FILENO, buffer, BUFFER_SIZE)) > 0)
    {
        size_t total_len = stash_len + bytes_read;
        char *data = malloc(total_len + 1);
        if (!data)
        {
            perror("Error");
            free(stash);
            return (1);
        }

        if (stash_len)
            memcpy(data, stash, stash_len);
        memcpy(data + stash_len, buffer, bytes_read);
        data[total_len] = '\0';
        free(stash);
        stash = NULL;
        stash_len = 0;

        size_t i = 0;
        while (i < total_len)
        {
            if (i + pat_len <= total_len &&
                strncmp(data + i, pattern, pat_len) == 0)
            {
                // write stars
                for (size_t j = 0; j < pat_len; j++)
                    write(STDOUT_FILENO, "*", 1);
                i += pat_len;
            }
            else
            {
                write(STDOUT_FILENO, &data[i], 1);
                i++;
            }
        }

        // Handle case where pattern might be split across buffer reads
        if (pat_len > 1)
        {
            size_t keep = (pat_len - 1 < total_len) ? pat_len - 1 : total_len;
            if (keep > 0)
            {
                stash = malloc(keep);
                if (!stash)
                {
			        perror("Error: ");
                    free(data);
                    return (1);
                }
                memcpy(stash, data + total_len - keep, keep);
                stash_len = keep;
            }
        }
        free(data);
    }

    if (bytes_read < 0)
    {
        perror("Error: ");
        free(stash);
        return (1);
    }
    free(stash);
    return (0);
}
