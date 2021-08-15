#include "libft.h"

char *ft_strnstr (const char *strB, const char *strA, size_t len)
{
	char *ptr = strB;
	bool found = false;
	int countA = 0;
	int countB = 0;
	int ind = 0;
	if (countA == "\0")
	{
		return ptr;
	}
	else
	{
		while (strB != "\0" || found == false)
		{
			if (*strB == *strA)
			{
				countA == 0;
				countB == 0;
				ind = 0;
				while (((*strA != "\0" && *strB != "\0") && ind != len) && (found == false && *strA == *strB))
				{
					strA++;
					strB++;
					countA++;
					countB++;
					ind++;
				}
				if (strA == "\0" || ind == len)
				{
					found = true;
				}
				for (int i = 1; i <= countA; i++)
				{
					strA--;
				}
				for (int i = 1; i <= countB; i++)
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
