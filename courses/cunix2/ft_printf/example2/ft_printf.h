#ifndef _FT_PTINTF_H_
# define _FT_PRINTF_

#include <stdio.h>
#include <stdarg.h>
#include <stdbool.h>

void ft_printf (char *format_str, ...);
char *to_string (int n, int base);
int my_atoi (char *s);

#endif
