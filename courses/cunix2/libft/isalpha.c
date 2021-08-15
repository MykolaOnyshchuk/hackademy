#include "libft.h"

int ft_isalpha (int ch)
{
	int ind = (int) ch;
	if ((ind >= 65 && ind <= 90) || (ind >= 97 && ind <= 122))
	{
		return ind;
	}
	else
	{
		return 0;
	}
}
