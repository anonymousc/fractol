/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessadik <aessadik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 01:28:19 by aessadik          #+#    #+#             */
/*   Updated: 2024/05/12 20:02:48 by aessadik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/fractol.h"
#include <string.h>

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2 && *s1 && *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

static int	valid_str(char *s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (!((s[i] >= '0' && s[i] <= '9') || s[i] == '.' || s[i] == '-'
				|| s[i] == '+'))
			return (0);
		if (s[i] == '.')
			count++;
		i++;
	}
	return ((count == 1 || count == 0));
}

static int	sign1(char c, int *i)
{
	int	s;

	s = 1;
	if (c == '-' || c == '+')
	{
		if (c == '-')
			s = -1;
		i++;
	}
	return (s);
}

int	ft_atof(const char *s, double *arg)
{
	int		i;
	int		sign;
	double	dec;
	int		flag;

	if (!valid_str((char *)s))
		return (0);
	flag = 0;
	dec = 0.1;
	i = 0;
	sign = sign1(s[i], &i);
	while (s[i])
	{
		if (flag == 0 && (s[i] >= '0' && s[i] <= '9'))
			(*arg) = (*arg) * 10 + s[i] - '0';
		else if (flag == 1 && (s[i] >= '0' && s[i] <= '9'))
		{
			(*arg) = (*arg) + dec * (s[i] - '0');
			dec *= 0.1;
		}
		else if (s[i] == '.')
			flag = 1;
		i++;
	}
	return ((*arg) *= sign, 1);
}
