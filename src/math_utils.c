/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcgar2 <marcgar2@student.42madrid.org    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:09:27 by marcgar2          #+#    #+#             */
/*   Updated: 2025/03/11 08:01:27 by marcgar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

double map(double unscaled, double new_min, double new_max, double old_max)
{
	return ((new_max - new_min) * (unscaled) / (old_max) + new_min);
}

t_complex complex_sum(t_complex z1, t_complex z2)
{
	t_complex res;

    res.x = z1.x + z2.x;
    res.y = z1.y + z2.y;
    return (res);
}

t_complex square_sum(t_complex z)
{
    t_complex res;

    res.x = (z.x * z.x) - (z.y * z.y);
    res.y = 2 * z.x * z.y;
    return (res);
}