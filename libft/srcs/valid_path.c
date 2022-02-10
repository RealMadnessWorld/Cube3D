#include "../includes/libft.h"

int		valid_path(char *path)
{
	if (open((path), O_RDONLY) < 0)
	{
		printf("hi\n");
		return (0);
	}
	printf("Yes\n");
	return (1);
}