/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcgar2 <marcgar2@student.42madrid.org    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 13:20:27 by marcgar2          #+#    #+#             */
/*   Updated: 2025/03/11 07:53:31 by marcgar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int close_win(t_fractal *fractal)
{
    mlx_destroy_image(fractal->mlx_connect, fractal->img.img_ptr);
    mlx_destroy_window(fractal->mlx_connect, fractal->mlx_window);
    mlx_destroy_display(fractal->mlx_connect);
    free(fractal->mlx_connect);
    exit(EXIT_SUCCESS);
}

int key_input(int keysym, t_fractal *fractal)
{
    if (keysym == XK_Escape)
        close_win(fractal);
    if (keysym == XK_Left)
        fractal->shift_x += (0.5 * fractal->zoom);
    else if (keysym == XK_Right)
        fractal->shift_x -= (0.5 * fractal->zoom);
    else if (keysym == XK_Up)
        fractal->shift_y -= (0.5 * fractal->zoom);
    else if (keysym == XK_Down)
        fractal->shift_y += (0.5 * fractal->zoom);
    else if (keysym == XK_plus)
        fractal->iter_def += 10;
    else if (keysym == XK_minus)
        fractal->iter_def -= 10;
    fractal_render(fractal);
    return (0);
}

int mouse_input(int button, int x, int y, t_fractal *fractal)
{
    (void)x;
    (void)y;
    if (button == Button5)
        fractal->zoom *= 0.95;
    else if (button == Button4)
        fractal->zoom *= 1.05;
    fractal_render(fractal);
    return (0);
}

int julia_track(int x, int y, t_fractal *fractal)
{
    if (!ft_strncmp(fractal->name, "julia", 5))
    {
        fractal->julia_x = (map(x, -2, +2, WIDTH) * fractal->zoom) + fractal->shift_x;
        fractal->julia_y = (map(y, +2, -2, HEIGHT) * fractal->zoom) + fractal->shift_y;
        fractal_render(fractal);
    }
    return (0);
}