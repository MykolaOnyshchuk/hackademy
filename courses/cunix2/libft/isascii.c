#include "libft.h"

int ft_isascii (int ch)
{
	int ind = (int) ch;
	if (ind >= 0 && ind <= 127)
	{
		return ind;
	}
	else
	{
		return 0;
	}
}
