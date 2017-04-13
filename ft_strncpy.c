char	*ft_strcpy(char *dst, const char *src, size_t n)
{
	size_t	i;

	i = -1;
	while (i < n && src[++i] != '\0')
		dst[i] = src[i];
	dst[i] = '\0';
	return (dst);
}
