NAME 			= cub3D
LIBFT_PATH 		= ./libft
MINILIBX_PATH   = ./mlx_linux
SRCS 			=	main.c \
					./parsing/init_game.c \
					./parsing/init_map.c \
					./parsing/parsing_utils.c \
					./parsing/parse_map.c \

OBJS			= ${SRCS:.c=.o}
INCLUDE 		= cube3d.h
LIBFT 			= libft
MINILIBX 		= miniLibX
CC				= cc -g3 -Wall -Wextra -Werror -I./includes
RM				= rm -f
LIBFLAGS 		= -I ./libft -L ./libft -L . ./libft/*.c
UNAME := $(shell uname)

ifeq ($(UNAME), Linux)
	INCLUDES = -I/usr/include -Imlx
	MLX_LIB = $(MLX_DIR)/libmlx_$(UNAME).a
	MLX_FLAGS = -I ./miniLibX -L ./miniLibX -lmlx -lX11 -lXext
else
	INCLUDES = -I/opt/X11/include -Imlx
	MLX_LIB = $(MLX_DIR)/libmlx_$(UNAME).a
	MLX_FLAGS = -Lmlx -lmlx -L/usr/X11/lib -lXext -lX11 -framework OpenGL -framework AppKit
endif

all:			libft_all minilibx_all ${NAME}
$(NAME):		${OBJS}
				@$(CC) $(LIBFLAGS) libft.a libmlx.a $(OBJS) $(MLXFLAGS) -o $@
clean:			libft_clean minilibx_clean
				@${RM} ${OBJS}
fclean:			libft_fclean clean
				@${RM} ${NAME}
re:				fclean all

libft_all:
	make -C $(LIBFT_PATH) all
	cp ./libft/libft.a libft.a

libft_clean:
	make -C $(LIBFT_PATH) clean

libft_fclean:
	make -C $(LIBFT_PATH) fclean
	$(RM) libft.a

minilibx_all:
	make -C $(MINILIBX_PATH) all
	cp ./mlx_linux/libmlx.a libmlx.a

minilibx_clean:
	make -C $(MINILIBX_PATH) clean
	$(RM) libmlx.a

norm:
	find . -path ./mlx_linux -prune -o -name 'Makefile' -prune -o -name '*.c' -print -o -name '*.h' -print | xargs norminette


.PHONY: all fclean clean re
