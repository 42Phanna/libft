char	*ft_strstr(const char *str, const char *tofind)
{
	int	i;
	int	j;

	i = 0;
	while(str[i] != '\0')
	{
		j = 0;
		while (str[i + j] == tofind[j] && tofind[j] != '\0')
		{
			j++;
		}
		if (tofind[j] == '\0')
			return (str + i);
		else
			i++;
	}
	return (0);
}
#include <stdio.h>
int	main()
{
	printf("%s\n", ft_strstr("Helllllllllllllllllllllllllllllokikou", "llo"));
	return (0);
}
