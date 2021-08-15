#include "libft.h"

void *ft_memcpy (const void *dest, const void *source, size_t n)
{
	char *cdest = (char *) dest;
	char *csource = (char *) source;
	for (int i = 0; i < n; i++)
	{
		*cdest = *csource;
		cdest++;
		csource++;
	}
	return dest;
}
