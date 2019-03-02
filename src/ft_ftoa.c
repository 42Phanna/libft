/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bam <bam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/01 17:18:32 by bam               #+#    #+#             */
/*   Updated: 2019/01/08 13:58:54 by phanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ftoa(float f, int d)
{
	char	*tmp;
	int		i;
	int		tmpf;

	i = 0;
	tmpf = f;
	f < 0 ? tmpf = -f : 0;
	if (d < 0)
		d = 6;
	tmp = ft_itoa(f);
	f = f - (int)f;
	while (i < d)
	{
		f = f * 10;
		i++;
	}
	tmp = ft_strjoin(tmp, ".");
	tmp = ft_strjoin(tmp, ft_itoa(tmpf));
	return (tmp);
}
