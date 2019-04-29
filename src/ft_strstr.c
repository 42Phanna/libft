/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanna <phanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 12:29:52 by phanna            #+#    #+#             */
/*   Updated: 2019/04/29 16:03:31 by phanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *tofind)
{
	int		i;
	int		j;
	char	*tmp;

	tmp = (char *)str;
	i = 0;
	if (tmp[i] == '\0' && tofind[i] != '\0')
		return (0);
	if (tmp[i] == '\0')
		return (tmp);
	while (tmp[i] != '\0')
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
		while (tmp[i + j] == tofind[j] && tofind[j] != '\0' && len > j + i)
			j++;
		if (tofind[j] == '\0')
			return (tmp + i);
		i++;
	}
	return (0);
}