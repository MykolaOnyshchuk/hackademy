#include "libft.h"

char *ft_strjoin (const char *s1, const char *s2)
{
	int len1 = 0;
	int len2 = 0;
	while (s1[len1] != '\0')
	{
		len1++;
	}
	while (s2[len2] != '\0')
	{
		len2++;
	}
	char *new_s;
	if (new_s = (char *) malloc((len1 + len2 + 1) * sizeof (*new_s)))
	{}
	else
	{
		return NULL;
	}
	for (int i = 0; i < len1 + len2; i++)
	{
		if (i < len1)
		{
			new_s[i] = s1[i];
		}
		else
		{
			new_s[i] = s2[i - len1];
		}
	}
	new_s[len1 + len2] = '\0';
	return new_s;
}
