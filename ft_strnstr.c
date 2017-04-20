/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 12:52:52 by phanna            #+#    #+#             */
/*   Updated: 2017/04/18 13:52:40 by phanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *tofind, size_t len)
{
	size_t	i;
	size_t	j;
	char	*tmp;

	tmp = (char *)str;
	i = 0;
	if (tmp[i] == '\0' && tofind[i] != '\0')
		return (0);
	if (tmp[i] == '\0')
		return (tmp);
	while (tmp[i] != '\0' && len > i)
	{
		j = 0;
		while (tmp[i + j] == tofind[j] && tofind[j] != '\0')
			j++;
		if (tofind[j] == '\0')
			return (tmp + i);
		i++;
	}
	return (0);
}
#include <stdio.h>
int	main()
{
	const char	a[] = "IBMZIRIBMZE123";
	const char	b[] = "MZIRIBMZE";
	printf("%s\n", ft_strnstr(a, b, 1500));
	return (0);
}
