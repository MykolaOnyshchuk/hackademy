#include <stdio.h>
#include <math.h>

int my_strcmp(char *str1, char *str2)
{
	int i = 0;
	int diff = 0;
	while ((str1[i] != '\0' && str2[i] != '\0') && diff == 0)
	{
		if (str1[i] != '\0' && str2[i] == '\0')
		{
			diff = 1;
		}
		else if (str1[i] == '\0' && str2[i] != '\0')
		{
			diff = -1;
		}
		else
		{
			if (str1[i] > str2[i])
			{
				diff = 1;
			}
			else if (str1[i] < str2[i])
			{
				diff = -1;
			}
		}
	}
	return diff;
}
