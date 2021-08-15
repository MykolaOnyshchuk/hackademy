#include "libft.h"

int ft_isdigit (int ch)
{
	int ind = (int) ch;
	if (ind >= 48 && ind <= 57)
	{
		return ind;
	}
	else
	{
		return 0;
	}
}
