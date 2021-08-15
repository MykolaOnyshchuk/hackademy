#include "libft.h"

void *ft_memchr (const void *arr, int c, size_t n)
{
	char *carr = (char *) arr;
	bool found = true;
	for (int i = 0; i < n; i++)
	{
		if (carr[i] == c)
		{
			return &carr[i];
		}
	}
	return NULL;
}
