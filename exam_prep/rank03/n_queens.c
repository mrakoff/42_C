#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void print(int *board, int n)
{
	int i = 0;

	while (i < n)
	{
		fprintf(stdout, "%d", board[i]);
		if (i < n - 1)
			fprintf(stdout, " ");
		i++;
	}
	fprintf(stdout, "\n");
}

int solve(int *board, int col, int row)
{
	int prev = 0;
	// check if position is safe
	while (prev < col)
	{
		int prow = board[prev];
		if (prow == row)
			return (0);
		if (prow - row == prev - col || prow - row == ((prev - col) * -1))
			return (0);
		prev++;
	}
	return (1);
}

void backtrack(int n, int col, int *board)
{
	if (col == n)
	{
		print(board, n);
		return ;
	}
	int row = 0;
	while (row < n) // check every row
	{
		if (solve(board, col, row))
		{
			board[col] = row;
			backtrack(n, col + 1, board);
		}
		row++;
	}
}

int main(int ac, char **av)
{
	int col = 0;
	int n = atoi(av[1]);
	int *board;

	if (ac != 2 || n <= 3)
		return (1);
	
	board = malloc(sizeof(int) * n);
	backtrack(n, col, board);
}