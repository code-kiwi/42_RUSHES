NAME					=	connect4
CC						=	cc
CFLAGS					=	-Wall -Wextra -Werror -MD -MP -O3
HFLAGS					=	-I$(INCS) -I$(LIBFT_HEADERS_DIR) -I$(MLX_DIR)

INCS					=	includes/
SRCDIR					=	src/
OBJDIR					=	.build/

SRC						=	main.c \
							print_board.c \
							print_slot.c \
							print_status.c \
							init_board.c \
							free_board.c \
							game_loop.c \
							get_player_input.c \
							get_ai_input.c \
							check_for_win.c \
							is_coll_full.c \
							is_valid_equal.c \
							coin_utils.c \
							game_loop_ui.c \
							t_mlx_init.c \
							t_mlx_destroy.c \
							t_image_init.c \
							t_mlx_mouse_utils.c \
							t_mlx_add_hook.c \
							t_mlx_render.c \
							t_mlx_events.c \
							t_mlx_draw_pixel.c \
							t_mlx_draw_line.c \
							t_mlx_draw_circle.c \
							t_mlx_draw_rectangle.c \
							math.c \

LIB_DIR					=	lib/
LIBFT_SUBDIR			=	libft/
LIBFT_DIR				=	$(addprefix $(LIB_DIR), $(LIBFT_SUBDIR))
LIBFT_FILE				=	libft.a
LIBFT					=	$(addprefix $(LIBFT_DIR), $(LIBFT_FILE))
LIBFT_HEADERS_SUBDIR	=	includes/
LIBFT_HEADERS_DIR		=	$(addprefix $(LIBFT_DIR), $(LIBFT_HEADERS_SUBDIR))
LIBFT_FLAGS				=	-L$(LIBFT_DIR) -lft

MLX_SUBDIR				=	mlx/
MLX_DIR					=	$(addprefix $(LIB_DIR), $(MLX_SUBDIR))
MLX_FILE				=	libmlx_Linux.a
MLX						=	$(addprefix $(MLX_DIR), $(MLX_FILE))
MLX_HEADERS				=	$(addprefix $(MLX_DIR), $(MLX_HEADER_FILE))
MLX_FLAGS				=	-L$(MLX_DIR) -lmlx_Linux -lXext -lX11

OBJ						=	$(addprefix $(OBJDIR), $(SRC:.c=.o))
DEP						=	$(addprefix $(OBJDIR), $(SRC:.c=.d))

$(NAME) : $(LIBFT) $(MLX) $(OBJ)
	$(CC) $(CFLAGS) $(HFLAGS) $(OBJ) $(LIBFT_FLAGS) $(MLX_FLAGS) -o $(NAME)

-include $(DEP)

$(OBJDIR)%o : $(SRCDIR)%c | $(OBJDIR)
	$(CC) -c $(CFLAGS) $(HFLAGS) $(DEPFLAGS) $< -o $@

$(LIBFT) : FORCE
	$(MAKE) -sC $(LIBFT_DIR)

$(MLX) : FORCE
	$(MAKE) -sC $(MLX_DIR) > /dev/null 2>&1

$(OBJDIR) :
	mkdir -p $@

.PHONY: clean
clean :
	$(MAKE) -sC $(LIBFT_DIR) clean
	$(MAKE) -sC $(MLX_DIR) clean > /dev/null 2>&1
	$(RM) -r $(OBJDIR)

.PHONY: fclean
fclean : clean
	$(RM) $(NAME)

.PHONY: re
re : fclean all

.PHONY: all
all : $(NAME)

.PHONY: FORCE
FORCE:
