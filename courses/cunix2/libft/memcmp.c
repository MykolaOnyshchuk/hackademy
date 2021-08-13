int memcmp (const void * buf1, const void *buf 2, size_t count)
{
	char *cbuf1 = (char *) buf1;
	char *cbuf2 = (char *) buf2;
	int result = 0;
	for (int i = 0; i < count; i++)
	{
		if (*cbuf1 > *cbuf2)
		{
			result = 1;
			break;
		}
		else if (*cbuf1 < *cbuf2)
		{
			result = -1;
			break;
		}
	}
	return result;
}
