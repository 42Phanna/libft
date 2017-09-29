/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 14:56:29 by phanna            #+#    #+#             */
/*   Updated: 2017/09/25 09:41:44 by phanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*tab;

	i = 0;
	while (s1[i] != '\0')
		i++;
	if (!(tab = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		tab[i] = s1[i];
		i++;
	}
	tab[i] = '\0';
	return (tab);
}
