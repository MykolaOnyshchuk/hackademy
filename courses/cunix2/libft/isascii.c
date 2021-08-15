#include "libft.h"

int ft_isascii (int ch)
{
	int ind = (int) ch;
	if (ind >= 0 && ind <= 127)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
