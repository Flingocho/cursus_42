SRCS		=	so_long.c controls_manager.c counter_render.c counter_render_2.c \
			flood_fill.c init_misc.c  map_operators.c map_check.c enemy.c \
			misc_functions.c render_window.c terminate_process.c 
INCLUDE		=	include
LIBFT		=	libft
FTPRINTF	=	ftprintf
OBJDIR		=	objs/
OBJS		=	$(SRCS:%.c=$(OBJDIR)%.o)
CC			=	cc -I$(INCLUDE) -Wall -Wextra -Werror
RM			=	rm -f
AR			=	ar rcs
NAME		=	so_long

all:		lib $(NAME)

bonus:		lib $(NAME)

lib:
			make -C $(LIBFT)

$(NAME):	$(OBJS)
			make -C $(LIBFT)
			$(CC) $(OBJS) -L$(LIBFT) -lft -Lminilibx-linux -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz -o $(NAME)

$(OBJDIR)%.o: %.c
			@mkdir -p $(OBJDIR)
			$(CC) -c $< -o $@

clean:
			$(RM) $(OBJS)
			@rm -rf $(OBJDIR)
			make -C  $(LIBFT) clean

fclean:		clean
			$(RM) $(NAME)
			make -C $(LIBFT) fclean

re:			fclean all

.PHONY:		all lib clean fclean re bonus
