NAME		= so_long
BONUS_NAME	= so_long_bonus
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f

SRC_DIR		= src/
SRC_BONUS_DIR	= src_bonus/
OBJ_DIR		= obj/
OBJ_BONUS_DIR	= obj_bonus/
INC_DIR		= include/
MLX_DIR		= mlx_linux/

VPATH		= $(SRC_DIR)
SRC_FILES	= so_long.c so_long_movement.c so_long_image.c so_long_check.c so_long_parser.c so_long_flood.c so_long_clean.c so_long_winner.c
OBJ_FILES	= $(addprefix $(OBJ_DIR), $(notdir $(SRC_FILES:.c=.o)))

VPATH_BONUS	= $(SRC_BONUS_DIR)
SRC_BONUS_FILES	= so_long.c so_long_movement.c so_long_image.c so_long_check.c so_long_parser.c so_long_flood.c so_long_clean.c so_long_winner.c so_long_loser.c
OBJ_BONUS_FILES	= $(addprefix $(OBJ_BONUS_DIR), $(notdir $(SRC_BONUS_FILES:.c=.o)))

INCLUDES	= -I$(INC_DIR) -I$(MLX_DIR) -I$(LIBFT_DIR)

MLX_FLAGS	= -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

LIBFT_DIR	= include/libft
LIBFT		= $(LIBFT_DIR)/libft.a
LIBFT_FLAGS	= -L$(LIBFT_DIR) -lft

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_BONUS_DIR):
	@mkdir -p $(OBJ_BONUS_DIR)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR) --no-print-directory > /dev/null

$(LIBFT_BONUS):
	@$(MAKE) -C $(LIBFT_DIR) bonus --no-print-directory > /dev/null

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_BONUS_DIR)%.o: $(SRC_BONUS_DIR)%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(LIBFT) $(OBJ_FILES)
	$(CC) $(OBJ_FILES) $(LIBFT_FLAGS) $(MLX_FLAGS) -o $(NAME)

$(BONUS_NAME): $(LIBFT) $(OBJ_BONUS_FILES)
	$(CC) $(OBJ_BONUS_FILES) $(LIBFT_FLAGS) $(MLX_FLAGS) -o $(BONUS_NAME)

bonus: $(OBJ_BONUS_DIR) $(BONUS_NAME)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(RM) -r $(OBJ_DIR) $(OBJ_BONUS_DIR)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(RM) $(NAME) $(BONUS_NAME)

re: fclean all

re_bonus: fclean bonus

.PHONY: all clean fclean re bonus re_bonus