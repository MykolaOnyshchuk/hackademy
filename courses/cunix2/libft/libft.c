#ifdef LIBFT_H
# define LIBFT_H

void ft_bzero (void *s, size_t n);

char *ft_strdup (const char *str);

char *ft_strchr (const char *str, int ch);

int ft_isalpha (int ch);

int ft_isdigit (int ch);

int ft_isascii (int ch);

int ft_upper (int ch);

int ft_tolower (int ch);

int ft_abs (int num);

char *ft_strstr (const char *strB, const char *strA);

char *ft_strnstr (const char *strB, const char *strA, size_t len);

void *ft_memset (void *dest, int c, size_t n);

void *ft_memcpy (void *dest, const void *source, size_t n);

void *ft_memccpy (void *dest, const void *source, int c, size_t n);

void ft_memmove (void* dest, void *src, size_t n);

void *ft_memchr (const void *arr, int c, size_t n);

int memcmp (const void *buf1, const void *buf2, size_t count);

#endif
