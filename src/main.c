/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcgar2 <marcgar2@student.42madrid.org    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 21:26:30 by marcgar2          #+#    #+#             */
/*   Updated: 2025/03/11 20:01:58 by marcgar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int main(int argc, char **argv)
{
	t_fractal frac;

	if (((argc == 2 && ft_strncmp(argv[1], "mandelbrot", 10) == 0)) 
		|| (argc == 4 && !ft_strncmp(argv[1], "julia", 5) == 0))
	{
		check_julia(&frac, argv, argc);
		fractal_init(&frac);
		fractal_render(&frac);
		mlx_loop(frac.mlx_connect);
	}
	else
	{
		putstr_fd(ERROR_MSG, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}