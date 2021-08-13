void *ft_memcpy (void *dest, const void *source, size_t n)
{
	char *ptr = dest;
	for (int i = 0; i < n; i++)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = "\0";
	return ptr;
}
