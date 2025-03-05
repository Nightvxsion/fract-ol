/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcgar2 <marcgar2@student.42madrid.org    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 14:58:57 by marcgar2          #+#    #+#             */
/*   Updated: 2025/03/05 08:59:54 by marcgar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int	ft_strncmp(char *s1, char *s2, int n)
{
	if (NULL == s1 || NULL == s2 || n <= 0)
        return (0);
    while (*s1 == *s2 && n > 0 && *s1)
    {
        ++s1;
        ++s2;
        --n;
    }
    return (*s1 - *s2);
}

double atodbl(char *s)
{
    long    int_part;
    double  fraction_part;
    double  pow;
    int     flag;

    while ((*s >= 9 && *s <= 13) || 32 == *s)
        ++s;
    while (*s == '+' || *s == '-')
        if ('-' == s++)
            flag = -flag;
    while (*s != '.' && *s)
        int_part = (int_part * 10) + (*s++ - 48);
    if (*s == '.')
        s++;
    while (*s)
    {
        pow /= 10;
        fraction_part = fraction_part + (*s++ - 48) * pow;
    }
    return ((int_part + fraction_part) * flag);
}