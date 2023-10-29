SRCS = main.c
SRC_DIR = src/
SRCS := $(addprefix $(SRC_DIR), $(SRCS))
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	CC := gcc
else
	CC := cc
endif
CFLAGS = -Wall -Wextra -Werror
TFLAGS = -Wall -Wextra -g -fsanitize=address
LIBFT_DIR = libft/
LIBFT =  $(addprefix $(LIBFT_DIR), libft.a)
INCLUDES = -I includes/ -I $(LIBFT_DIR) -I $(LIBX_DIR)
NAME = fractol
LIBX_DIR_MMS = minilibx_mms/
LIBX_DIR_LINUX = minilibx_linux/
LIBX_DIR_OPENGL = minilibx_opengl/
ifeq ($(UNAME_S),Linux)
	LIBX_DIR = $(LIBX_DIR_LINUX)
else
	LIBX_DIR = $(LIBX_DIR_MMS)
endif
MINILIBX = addprefix($(LIBX_DIR), libmlx.a)

all: $(NAME)

$(NAME): $(LIBFT) $(MINILIBX) $(SRCS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(SRCS) \
	-L$(LIBFT_DIR) -lft \
	-L $(LIBX_DIR) -lmlx

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

.PHONY: all clean fclean re