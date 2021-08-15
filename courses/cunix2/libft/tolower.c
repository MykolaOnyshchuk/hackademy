#include "libft.h"

int ft_tolower(int ch)
{
	if (ch >= 65 && ch <= 90)
	{
		ch += 30;
	}
	return ch;
}
