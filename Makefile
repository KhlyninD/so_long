
NAME            = so_long
CC              = cc
CFALGS          = -O2 -Wall -Wextra -Werror
LINKS 			= -lmlx -framework OpenGL -framework AppKit
RM              = rm -rf
LIBFT_DIR       = libft/
LIBFT           = $(LIBFT_DIR)libft.a
SRC_DIR         = src/
HEADER          = ./inc/so_long.h
SRC_FILES       = so_long.c\
				free_error.c\
				get_next_line.c\
				parsing.c\
				check.c\
				render.c\
				open_img.c\
				move.c\

OBJS            = $(patsubst %.c, %.o, $(addprefix $(SRC_DIR), $(SRC_FILES)))
all:            $(LIBFT) $(NAME)
$(NAME)			: $(OBJS) $(HEADER) $(LIBFT)
			$(CC) $(CFLAGS) $(OBJS) $(LINKS) -L$(LIBFT_DIR) -lft -o $@
$(SRC_DIR)%.o	: $(SRC_DIR)%.c $(HEADER) $(LIBFT)
			$(CC) $(CFLAGS) -c $< -o $@
$(LIBFT):
		make -C $(LIBFT_DIR)
clean:
		$(RM) $(OBJS) 
		make -C $(LIBFT_DIR) clean
fclean: clean
		$(RM) $(NAME) 
		make -C $(LIBFT_DIR) fclean
re:		fclean all
.PHONY: all clean fclean re