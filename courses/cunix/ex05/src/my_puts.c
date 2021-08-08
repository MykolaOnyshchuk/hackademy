#include <stdio.h>
#include <unistd.h>
#include <string.h>

int my_puts (const char *s)
{
	int n = strlen(s);
	write(1, s, n);
	write(1, "\n", 1);
	return n;
}
