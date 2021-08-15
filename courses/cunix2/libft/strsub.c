#include "libft.h"

char *ft_strsub (const char *s, unsigned int start, size_t len)
{
	int count = 0;
	while (s[count] != '\0')
	{
		count++;
	}
	if (count < start)
	{
		char *term = (char *)malloc(sizeof(char));
		term[0] = '\0';
		return term;
	}
	char *new_s;
	int new_s_len;
	if (count < len)
	{
		new_s_len = count;
	}
	else
	{
		new_s_len = len;
	}
	if(new_s = (char *) malloc((new_s_len + 1) * sizeof(char)))
	{
		for (int i = start; i < new_s_len + start; i++)
		{
			new_s[i - start] = s[i];
		}
		new_s[new_s_len] = '\0';
		return new_s;
	}
	else
	{
		return NULL;
	}
}
