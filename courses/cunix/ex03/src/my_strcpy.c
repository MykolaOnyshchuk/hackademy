#include <stdio.h>

char *my_strcpy (char *dest, const char *src)
{
	int i = 0;
	while (i == 0 || src[i - 1] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	return dest;
		
}
