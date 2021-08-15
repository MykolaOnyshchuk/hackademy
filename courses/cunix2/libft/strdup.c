#include "libft.h"

char *ft_strdup (const char *str)
{
	char *new_str;
	int i = 0;
	while (str[i])
	{
		i++;
	}
	new_str =  malloc((i + 1) * sizeof(*str));
	for (int j = 0; j < i; j++)
	{
		new_str[j] = str[j];
	}
	new_str[i] = '\0';
	return new_str;
}
