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
CC				= gcc -g -Wall -Wextra -Werror -I./includes
RM				= rm -f
MLXFLAGS 		= -I ./miniLibX -L ./miniLibX -lmlx -lX11 -lXext
LIBFLAGS 		= -I ./libft -L ./libft -L . ./libft/*.c


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

.PHONY: all fclean clean re

