#ifndef _LIBFT_H_
# define _LIBFT_H_

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>

void ft_bzero (void *s, size_t n);

char *ft_strdup (const char *str);

char *ft_strchr (const char *str, int ch);

int ft_isalpha (int ch);

int ft_isdigit (int ch);

int ft_isascii (int ch);

int ft_toupper (int ch);

int ft_tolower (int ch);

int ft_abs (int num);

char *ft_strstr (const char *strB, const char *strA);

char *ft_strnstr (const char *strB, const char *strA, size_t len);

void *ft_memset (void *dest, int c, size_t n);

void *ft_memcpy (const void *dest, const void *source, size_t n);

void *ft_memccpy (void *dest, const void *source, int c, size_t n);

void ft_memmove (void* dest, void *src, size_t n);

void *ft_memchr (const void *arr, int c, size_t n);

int ft_memcmp (const void *buf1, const void *buf2, size_t count);

void ft_striter (char *s, void (*f)(char *));

char *ft_strsub (const char *s, unsigned int start, size_t len);

char *ft_strjoin (const char *s1, const char *s2);

char *ft_strtrim (const char *s);

#endif
