/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcgar2 <marcgar2@student.42madrid.org    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 14:58:57 by marcgar2          #+#    #+#             */
/*   Updated: 2025/03/11 20:03:13 by marcgar2         ###   ########.fr       */
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
        if ('-' == *s++)
            flag = -flag;
    while (*s != '.' && *s)
        int_part = (int_part * 10) + (*s++ - '0');
    if (*s == '.')
        ++s;
    while (*s)
    {
        pow /= 10;
        fraction_part = fraction_part + (*s++ - '0') * pow;
    }
    return ((int_part + fraction_part) * flag);
}

void	putstr_fd(char *s, int fd)
{
	if (NULL == s || fd < 0)
		return ;
	if (*s != '\0')
	{
		write(fd, s, 1);
		putstr_fd(s + 1, fd);
	}
}

void    check_julia(t_fractal *fractal, char **argv, int argc)
{
    int i;

    i = 0;
    fractal->name = argv[1];
    if ((argc == 4 && ft_strncmp(argv[1], "julia", 5)) == 0)
    {
        while (argv[2][i] && argv[3][i])
        {
            if (((argv[2][i] >= '0' && argv[2][i] <= '9')
                || argv[2][i] == '.' || argv[2][i] == '+' || argv[2][i] == '-')
                && (argv[3][i] >= '0' && argv[3][i] <= '9')
                || argv[3][i] == '.' || argv[3][i] == '+' || argv[3][i] == '-')
                {
                    fractal->julia_x = atodbl(argv[2]);
                    fractal->julia_y = atodbl(argv[3]);
                }
                else
                {
                    putstr_fd(ERROR_MSG2, STDERR_FILENO);
                    exit(EXIT_FAILURE);
                }
                i++;
        }
    }
}