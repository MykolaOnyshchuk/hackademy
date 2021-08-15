#include "libft.h"

char *ft_strsub (const char *s, unsigned int start, size_t len)
{
	char *new_s;
	if (new_s = (char *) malloc(len * sizeof(*new_s)))
	{}
	else
	{
		return NULL;
	}
	for (int i = start; i < start + len; i++)
	{
		new_s[i - start] = s[i];
	}
	return new_s;
}
