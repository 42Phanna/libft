/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanna <phanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 15:12:00 by phanna            #+#    #+#             */
/*   Updated: 2019/04/29 15:36:15 by phanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int	ft_str_is_alpha(char *str)
{
	int i;
	int n;

	n = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] >= 'A' && str[i] <= 'Z') ||
				(str[i] >= 'a' && str[i] <= 'z'))
			i++;
		else
		{
			n = 1;
			i++;
		}
	}
	if (n == 1)
		return (0);
	else
		return (1);
}

int	ft_str_is_lowercase(char *str)
{
	int i;
	int n;

	n = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			i++;
		else
		{
			n = 1;
			i++;
		}
	}
	if (n == 1)
		return (0);
	else
		return (1);
}

int	ft_str_is_numeric(char *str)
{
	int i;
	int n;

	n = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
		{
			n = 1;
			i++;
		}
	}
	if (n == 1)
		return (0);
	else
		return (1);
}

int	ft_str_is_printable(char *str)
{
	int i;
	int n;

	n = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] >= 0 && str[i] <= 31) || str[i] == 127)
		{
			i++;
			n = 1;
		}
		else
			i++;
	}
	if (n == 1)
		return (0);
	else
		return (1);
}

int	ft_str_is_uppercase(char *str)
{
	int i;
	int n;

	n = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			i++;
		else
		{
			n = 1;
			i++;
		}
	}
	if (n == 1)
		return (0);
	else
		return (1);
}