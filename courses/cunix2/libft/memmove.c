#include "libft.h"

void ft_memmove (void *dest, void *src, size_t n)
{
	char *csrc = (char *)src;
	char *cdest = (char *)dest;
	char temp[n];
	for (int i = 0; i < n; i++)
	{
		temp[i] = csrc[i];
	}
	for (int i = 0; i < n; i++)
	{
		cdest[i] = temp[i];
	}
	free(temp);
}
