/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessadik <aessadik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 01:28:19 by aessadik          #+#    #+#             */
/*   Updated: 2024/04/26 20:41:17 by aessadik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/fractol.h"

int ft_strcmp(char *s1, char *s2)
{
    while (*s1 == *s2 && *s1 && *s2)
    {
        s1++;
        s2++;
    }
    return(*s1 - *s2);
}
double ft_atoi(char *str)
{
   double res;
   int s = 1;
    int i;
    while ((str[i] && str[i] >= 9 && str[i] <= 13) || str[i] == 32)
        i++;
    if(str[i] == '+' || str[i] == '-')
    {
        if (str[i] == '-')
            s = -s;
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        res = res * 10 + (str[i] - '0');
        i++;
    }
    return (res * s);
}

void parser(int ac ,char **av)
{
    if((ac == 2 && !ft_strcmp(av[1], "mandelbrot")) || 
    (ac == 4 && !ft_strcmp(av[1], "julia") && ft_atoi(av[2]) && ft_atoi(av[3])))
    return ;
}