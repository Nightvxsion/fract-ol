/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcgar2 <marcgar2@student.42madrid.org    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 22:25:15 by marcgar2          #+#    #+#             */
/*   Updated: 2025/03/03 15:31:03 by marcgar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h> //printf, bla bla bla
# include <stdlib.h> //malloc bla bla bla
# include <unistd.h> //basic functions write, open, etc...
# include <math.h> //math operations
# include <X11/X.h> //Keys signals and events
# include <X11/keysym.h> //Keyboard signals
# include "minilibx-linux/mlx.h"

//Just a error msg
#define ERROR_MSG "Enter \n\t"./fractol mandelbrot\" or \n\t"./fractol julia <val_1> <val_2>\"\n"

//Window size
#define WIDTH	800
#define HEIGHT	800

//BASIC COLORS
#define BLACK	0x000000 //Black in hex
#define WHITE	0xFFFFFF //White in hex
#define RED		0xFF0000 //Red in hex
#define GREEN	0x00FF00 //Green in hex
#define BLUE	0x0000FF //Blue in hex

//PSYCHODELIC COLORS
#define MAGENTA			0xFF00FF //Magenta in hex
#define LIME			0xCCFF00 //Green lime in hex
#define NEON_ORANGE		0xFF6600 //Orange in hex
#define PSYCHO_PURPLE	0X660066 //Purple in hex
#define TURQUOISE		0x33CCCC //Turquoise in hex
#define PINK			0xFF66B2 //Pink in hex
#define ELECTRIC_BLUE	0x0066FF //Another tone of blue in hex
#define LAVA_RED		0xFF3300 //Another tone of red

typedef struct s_complex
{
	double x; //Coordenadas 'x' (num. reales)
	double y; //Coordenadas 'y' (num. imaginarios -> num. i)
}	t_complex;

typedef struct s_display
{
	void	*img_ptr; //Interactua conla pantalla en sí (usando mlx)
	char	*pixels_dir; //Direccion donde se almacena el buffer de cada pixel
	int		bpp; //Almacena los bits para representar la imagen (de 16, 24, 32 dependiendo)
	int		endian; //Orden de los bytes
	int		line_len; //Longitud EN BYTES de cada fila de pixeles en la imagen 
}	t_display;

typedef struct s_fractal
{
	char		*name; //Fractal escogido
	void		*mlx_connect; //Hace ref a mlx_init()
	void		*mlx_window; //Hace ref a mlx_new_window()
	t_display	img; //Referencia a la lista anterior
	double		esc_value; //Valor de escape
	int			iter_def; //Render speed
	double		shift_x;
	double		shift_y;
	double		zoom;
	double		julia_x;
	double		julia_y;
}	t_fractal;


//WINDOW EVENTS
int close_win(t_fractal *fractal);
int key_input(int keysym, t_fractal *fractal);
int mouse_input(int button, int x, int y, t_fractal *fractal);
int julia_track(int x, int y, t_fractal *fractal);

//INIT EVENTS
void    fractal_init(t_fractal *fractal);

//UTILS
int	ft_strncmp(char *s1, char *s2, int n);

//MATH UTILS
double map(double unscaled, double new_min, double new_max, double old_max);
#endif