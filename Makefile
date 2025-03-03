NAME		= so_long
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f

# Directories
SRC_DIR		= src/
OBJ_DIR		= obj/
INC_DIR		= include/
MLX_DIR		= mlx_linux/

# Source files (without src/ prefix)
VPATH		= $(SRC_DIR)
SRC_FILES	= so_long.c so_long_movement.c so_long_image.c so_long_check.c so_long_parser.c so_long_flood.c so_long_clean.c
OBJ_FILES	= $(addprefix $(OBJ_DIR), $(notdir $(SRC_FILES:.c=.o)))

# Header files
INCLUDES	= -I$(INC_DIR) -I$(MLX_DIR) -I$(LIBFT_DIR)

# MLX flags
MLX_FLAGS	= -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

# Libft
LIBFT_DIR	= include/libft
LIBFT		= $(LIBFT_DIR)/libft.a
LIBFT_FLAGS	= -L$(LIBFT_DIR) -lft

# Default target
all: $(OBJ_DIR) $(NAME)

# Create object directory
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Rule to compile libft
$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

# Compile source files
$(OBJ_DIR)%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Link object files with MLX and Libft
$(NAME): $(LIBFT) $(OBJ_FILES)
	$(CC) $(OBJ_FILES) $(LIBFT_FLAGS) $(MLX_FLAGS) -o $(NAME)

# Clean object files
clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(RM) -r $(OBJ_DIR)

# Clean object files and executable
fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

# Clean and rebuild
re: fclean all

.PHONY: all clean fclean re