/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcgar2 <marcgar2@student.42madrid.org    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 14:10:24 by marcgar2          #+#    #+#             */
/*   Updated: 2025/03/11 08:05:52 by marcgar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

static void malloc_error(void)
{
    perror("Malloc error\n");
    exit(EXIT_FAILURE);
}

static void fractal_init_conf(t_fractal *fractal)
{
    fractal->esc_value = 4;
    fractal->iter_def = 100;
    fractal->zoom = 1.0;
    fractal->shift_x = 0.0;
    fractal->shift_y = 0.0;
}

static void events_conf(t_fractal *fractal)
{
    mlx_hook(fractal->mlx_window, KeyPress, KeyPressMask, key_input, fractal);
    mlx_hook(fractal->mlx_window, ButtonPress, ButtonPressMask, mouse_input, fractal);
    mlx_hook(fractal->mlx_window, DestroyNotify, StructureNotifyMask, close_win, fractal);
    mlx_hook(fractal->mlx_window, MotionNotify, PointerMotionMask, julia_track, fractal);
}

void    fractal_init(t_fractal *fractal)
{
    fractal->mlx_connect = mlx_init();
    if (NULL == fractal->mlx_connect)
        malloc_error();
    fractal->mlx_window = mlx_new_window(fractal->mlx_connect, WIDTH, HEIGHT, fractal->name);
    if (NULL == fractal->mlx_window)
    {
        mlx_destroy_display(fractal->mlx_connect);
        free(fractal->mlx_connect);
        malloc_error();
    }
    fractal->img.img_ptr = mlx_new_image(fractal->mlx_connect, WIDTH, HEIGHT);
    if (NULL == fractal->img.img_ptr)
    {
        mlx_destroy_window(fractal->mlx_connect, fractal->mlx_window);
        mlx_destroy_display(fractal->mlx_connect);
        free(fractal->mlx_connect);
        malloc_error();
    }
    fractal->img.img_ptr = mlx_get_data_addr(fractal->img.img_ptr, &fractal->img.bpp,
                                                &fractal->img.line_len, &fractal->img.endian);
    events_conf(fractal);
    fractal_init_conf(fractal);
}
