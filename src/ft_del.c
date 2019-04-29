/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanna <phanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 13:29:10 by phanna            #+#    #+#             */
/*   Updated: 2019/04/29 16:10:12 by phanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_delmap(int **map, int x, int y)
{
	int		i;

	i = 0;
	while (i < x)
	{
		map[i] = ft_memset(map[i], 0, y);
		free(map[i++]);
	}
	free(map);
}

void	ft_deltab(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		tab[i] = ft_memset(tab[i], 0, ft_strlen(tab[i]));
		free(tab[i++]);
	}
	free(tab);
}