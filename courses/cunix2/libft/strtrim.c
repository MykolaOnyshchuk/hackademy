#include "libft.h"

char *ft_strtrim (const char *s)
{
	int len = 0;
	while (*s)
	{
		len++;
	}
	int start = 0;
	int end = len - 1;
	while (s[end] == ' ' || s[end] == '\n' || s[end] == '\t')
	{
		end--;
	}
	while (s[start] == ' ' || s[start] == '\n' || s[start] == '\t')
	{
		start++;
	}
	char *new_s;
	if (new_s = (char *) malloc((end + 2 - start) * sizeof(*new_s)))
	{}
	else
	{
		return NULL;
	}
	for (int i = start; i <= end; i++)
	{
		new_s[i] = s[i];
	}
	new_s[end + 1] = '\0';
	return new_s;
}
