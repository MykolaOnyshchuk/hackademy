#include "libft.h"

char *ft_strstr (const char *strB, const char *strA)
{
	char *ptr = strB;
	bool found = false;
	int countA = 0;
	int countB = 0;
	if (*strA == '\0')
	{
		return ptr;
	}
	else
	{
		while (*strB != '\0' && found == false)
		{
			if (*strB == *strA)
			{
				countA = 0;
				countB = 0;
				while ((*strA != '\0' && *strB != '\0') && (found == false && *strA == *strB))
				{
					strA++;
					strB++;
					countA++;
					countB++;
				}
				if (*strA == '\0')
				{
					found = true;
				}
				for (int i = 1; i <= countA; i++)
				{
					strA--;
				}
				for (int i = 1; i <=countB; i++)
				{
					strB--;
				}
			}
		}
		if (found == true)
		{
			return ptr;
		}
		else
		{
			return NULL;
		}
	}
}
