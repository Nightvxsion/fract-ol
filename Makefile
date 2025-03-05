NAME = fractol
CC = gcc
CFLAGS = -Wall -Wextra -Werror 
MLX_DIR = ./minilibx-linux
LIBS = -L$(MLX_DIR) -Lminilibx-linux -lmlx_Linux -lX11 -lXext 

SRCS = src/main.c src/window_events.c src/init_fractal.c src/math_utils.c src/render.c src/utils.c
OBJS = $(SRCS:.c=.o)

all:  $(NAME)


$(NAME): $(OBJS)
	@echo " ███████╗██████╗  █████╗  ██████╗████████╗    ██████╗ ██╗     "
	@echo " ██╔════╝██╔══██╗██╔══██╗██╔════╝╚══██╔══╝   ██╔═══██╗██║     "
	@echo " █████╗  ██████╔╝███████║██║        ██║█████╗██║   ██║██║     "
	@echo " ██╔══╝  ██╔══██╗██╔══██║██║        ██║╚════╝██║   ██║██║     "
	@echo " ██║     ██║  ██║██║  ██║╚██████╗   ██║      ╚██████╔╝███████╗"
	@echo " ╚═╝     ╚═╝  ╚═╝╚═╝  ╚═╝ ╚═════╝   ╚═╝       ╚═════╝ ╚══════╝"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS)

%.o: %.c
	@$(CC) $(CFLAGS) -I$(MLX_DIR) -c $< -o $@

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all