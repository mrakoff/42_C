#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

// 5; 1 4 3 5 2
// 1 4
// 3 2
// 5
// target = 5; index = 0; sum = 0;
// 1 + 4 (index 0 + index 1); 

void	print(int subset[], int size)
{
	if (size == 0)
	{
		printf("\n");
		return ;
	}
	int i = 0;
	while (i < size)
	{
		if (i == size - 1)
			printf("%d", subset[i]);
		else
			printf("%d ", subset[i]);
		i++;
	}
	printf("\n");

}

void backtrack(int target, int sub_size, int set_size, int subset[], int set[], int index, int sum)
{
	if (index == set_size)
	{
		if (sum == target)
			print(subset, sub_size);
		return ;
	}

	backtrack(target, sub_size, set_size, subset, set, index + 1, sum);
	subset[sub_size] = set[index];
	backtrack(target, sub_size + 1, set_size, subset, set, index + 1, sum + set[index]);
}

int main(int ac, char **av)
{
	if (ac < 2)
		return (1);
	if (av[1][0] == '0' && av[1][1] == '\0')
	{
		printf("\n");
		return (0);
	}

	int target = atoi(av[1]);
	int set_size = ac - 2;
	if (set_size <= 0)
		return (1);
	int *subset = malloc(sizeof(int) * set_size);		// to store the subsets
	int *set = malloc(sizeof(int) * set_size); 			// for storing all available values
	if (!subset || !set)
		return (1);

	int i = 0;
	int j = 2;
	while (i < set_size)
	{
		set[i] = atoi(av[j]);
		i++;
		j++;
	}

	int index = 0;
	int sum = 0;
	int sub_size = 0;
	backtrack(target, sub_size, set_size, subset, set, index, sum);
	free(set);
	free(subset);
}