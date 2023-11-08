SRCS = main.c \
	solve_fractals.c \
	cmp_operators.c \
	cmp_operators_2.c \
	error_handlers.c \
	img_handlers.c \
	free_close_handlers.c \
	render.c \
	hooks.c
SRC_DIR = src/
SRCS := $(addprefix $(SRC_DIR), $(SRCS))
UNAME_S := $(shell uname -s)
CFLAGS = -Wall -Wextra -Werror
TFLAGS = -Wall -Wextra -g -fsanitize=address
LIBFT_DIR = libft/
LIBFT =  $(addprefix $(LIBFT_DIR), libft.a)
INCLUDES = -I $(LIBFT_DIR) -I $(LIBX_DIR)
NAME = fractol
LIBX_DIR_MMS = minilibx_mms/
LIBX_DIR_LINUX = minilibx_linux/
LIBX_DIR_OPENGL = minilibx_opengl/
LINKS = -L$(LIBFT_DIR) -lft -L$(LIBX_DIR) -lmlx
ifeq ($(UNAME_S),Linux)
	CC := gcc
	LIBX_DIR = $(LIBX_DIR_LINUX)
	LINKS += -lXext -lX11 -lm
	INCLUDES += -I includes_linux/
else
	CC := cc
	LIBX_DIR = $(LIBX_DIR_OPENGL)
	LINKS += -framework OpenGL -framework AppKit
	INCLUDES += -I includes/
endif
MINILIBX = addprefix($(LIBX_DIR), libmlx.a)

all: $(NAME)

$(NAME): $(LIBFT) $(MINILIBX) $(SRCS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(SRCS) $(LINKS)

test:
	$(CC) $(TFLAGS) $(INCLUDES) -o $(NAME) $(SRCS) $(LINKS)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(MINILIBX):
	make -C $(LIBX_DIR)

clean:
	make -C $(LIBFT_DIR) clean
	make -C $(LIBX_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re test