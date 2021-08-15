#include "libft.h"

void *ft_memccpy (void *dest, const void *source, int c, size_t n)
{
	char *cdest = (char *) dest;
	char *csource = (char*) source;
	char ch = (char) c;
	bool found = false;
	int i = 0;
	while (i != n && found == false)
	{
		if (csource[i] == ch)
		{
			found = true;
			break;
		}
		cdest[i] = csource[i];
		i++;
	}
	return dest;

}
