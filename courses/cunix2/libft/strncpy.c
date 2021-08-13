char *ft_strncpy (char *dest, const char *src, size_t count)
{
	char *ptr = dest;
	bool end = false;
	for (int i = 0; i < count; i++)
	{
		if (end == false)
		{
			*dest = *src;
			src++;
		}
		else
		{
			*dest = "\0";
		}
		if (*src == "\0")
		{
			end = true;
		}
		dest++;
	}
	*dest = "\0";
	return ptr;
}
