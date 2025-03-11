/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcgar2 <marcgar2@student.42madrid.org    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 09:10:27 by marcgar2          #+#    #+#             */
/*   Updated: 2025/03/11 20:05:07 by marcgar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../inc/fractol.h"

static void pixel_put(int x, int y, t_display *disp, int color)
{
    int delay;

    delay = (y * disp->line_len) + (x * (disp->bpp / 8));
    *(unsigned int *)(disp->pixels_dir + delay) = color;
}

static void mandel_n_julia(t_complex *z, t_complex *c, t_fractal *frac)
{
    if (!ft_strncmp(frac->name, "julia", 5))
    {
        c->x = frac->julia_x;
        c->y = frac->julia_y;
    }
    else
    {
        c->x = z->x;
        c->y = z->y;
    }
}

static void handle_pixels(int x, int y, t_fractal *frac)
{
    t_complex   z;
    t_complex   c;
    int         color;
    int         i;

    i = 0;
    z.x = (map(x, -2, +2, WIDTH) * frac->zoom) + frac->shift_x;
    z.y = (map(x, +2, -2, HEIGHT) * frac->zoom) + frac->shift_y;
    mandel_n_julia(&z, &c, frac);
    while (i < frac->iter_def)
    {
        z = complex_sum(square_sum(z), c);
        if ((z.x * z.x) + (z.y * z.y) > frac->iter_def)
        {
            color = map(i, BLACK, WHITE, frac->iter_def);
            pixel_put(x, y, &frac->img, color);
            return ;
        }
        ++i;
    }
    pixel_put(x, y, &frac->img, PSYCHO_PURPLE);
}

void    fractal_render(t_fractal *frac)
{
    int x;
    int y;

    y = -1;
    while (++y < HEIGHT)
    {
        x = -1;
        while (++x < WIDTH)
            handle_pixels(x, y, frac);
    }
    mlx_put_image_to_window(frac->mlx_connect, frac->mlx_window, frac->img.img_ptr, 0, 0);
}