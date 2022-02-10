#include "../includes/libft.h"

int		valid_path(char *path)
{
	if (open((path), O_RDONLY) < 0)
		return (0);
	return (1);
}