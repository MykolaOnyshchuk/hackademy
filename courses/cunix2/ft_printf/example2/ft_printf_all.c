#include "ft_printf.h"

void ft_printf (char *format_str, ...)
{
	char *str_copy;
	int i;
	char *s;
	va_list arg;
	va_start(arg, str_copy);
	bool plus = false;
	bool space = false;

	for (str_copy = format_str; *str_copy != '\0'; str_copy++)
	{
		while (*str_copy != '%')
		{
			putchar (*str_copy);
			str_copy++;
		}
		str_copy++;
		int count = 0;
		int char_num = 0;
		if (*str_copy == '+')
		{
			plus = true;
			str_copy++;
		}
		if (*str_copy == ' ')
		{
			space = true;
			str_copy++;
		}
		if (*str_copy == '0')
		{
			str_copy++;
			char str[10];
			int code = (int) *str_copy;
			while (code >= 48 && code <= 57)
			{
				str[count] = *str_copy;
				count++;
				str_copy++;
				code = (int) *str_copy;
			}
			str[count] = '\0';
			if (count > 0)
			{
				char_num = my_atoi(str);
			}
		}
		if (*str_copy == 'c')
		{
			i = va_arg(arg, int);
			putchar(i);
		}
		else if (*str_copy == 's')
		{
			puts(s);
		}
		else if (*str_copy == 'd')
		{
			if (i < 0)
			{
				i = i - (2 * i);
				putchar('-');
				puts(to_string(i, 10));
			}
		}
		else if (*str_copy == 'i')
		{
			if (plus == true)
			{
				if (i > 0)
				{
					putchar('+');
				}
			}
			else if (space == true)
			{
				if (i > 0)
				{
					putchar(' ');
				}
			}
			if (i < 0)
			{
				i = i - 2 * i;
				putchar('-');
			}
			char *int_pointer = to_string(i, 10);
			int it = 0;
			while (int_pointer[it] != '\0')
			{
				it++;
			}
			int zero_num = char_num - it;
			if (it < 0)
			{
				it = 0;
			}
			for (int j = 0; j < zero_num; j++)
			{
				putchar('0');
			}
			puts(int_pointer);
		}
	}
	va_end(arg);
}

char *to_string (int n, int base)
{
	static char rep[] = "0123456789";
	static char buf[50];
	char *ptr;
	ptr = &buf[49];
	*ptr = '\0';
	do 
	{
		*--ptr = rep[n % base];
		n /= base;
	} while (n != 0);
	return (ptr);
}

int my_atoi (char *s)
{
	int result = 0;
	for (int i = 0; s[i] != '\0'; i++)
	{
		result = result * 10 + s[i] - '0';
	}
	return result;
}
