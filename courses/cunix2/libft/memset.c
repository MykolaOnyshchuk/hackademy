#include "libft.h"

void *ft_memset (void* dest, int c, size_t n)
{
	char *cdest = (char *) dest;
	for (int i = 0; i < n; i++)
	{
		*cdest = c;
		cdest++;
	}
	*cdest = "\0";
	return cdest;
}
