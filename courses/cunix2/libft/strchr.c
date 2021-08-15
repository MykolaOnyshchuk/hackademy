#include "libft.h"

char *ft_strchr (const char *str, int ch)
{
	char character = (char) ch;
	int i = 0;
	bool found = false;
	while (*str != "\0" || found == false)
	{
		if (*str == character)
		{
			found = true;
			break;
		}
		str++;
	}
	if (found == true)
	{
		return *str;
	}
	else
	{
		return NULL;
	}
}
