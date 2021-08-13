#include <stdbool.h>

void *ft_memccpy (void *dest, const void *source, int c, size_t n)
{
	char ch = (char) c;
	char *ptr = dest;
	bool found = false;
	int i = 0;
	while (i != n && found == false)
	{
		if (*dest == ch)
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
