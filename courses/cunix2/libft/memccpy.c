#include "libft.h"

void *ft_memccpy (void *dest, const void *source, int c, size_t n)
{
	char *cdest = (char *) dest;
	char *csource = (char*) source;
	char ch = (char) c;
	char *ptr = cdest;
	bool found = false;
	int i = 0;
	while (i != n && found == false)
	{
		if (*cdest == ch)
		{
			found = true;
		}
		i++;
	}
	if (found == false)
	{
		return ptr;
	}
	else
	{
		return NULL;
	}

}
