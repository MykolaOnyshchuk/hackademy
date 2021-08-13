#include <stdbool.h>

void *ft_memchr (const void *arr, int c, size_t n)
{
	bool found = true;
	for (int i = 0; i < n; i++)
	{
		if (*arr == c)
		{
			found == true;
			break;
		}
		arr++;
		if (found == true)
		{
			return arr;
		}
		else
		{
			return NULL;
		}
	}

