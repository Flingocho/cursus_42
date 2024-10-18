SRCS		=	so_long.c map_check.c controls_manager.c map_check_utils.c \
                flood_fill.c sprites.c controls_manager_utils.c \
				sprites_utils.c
INCLUDE		=	include
LIBFT		=	libft
FTPRINTF	=	ftprintf
OBJDIR		=	objs/
OBJS		=	$(SRCS:%.c=$(OBJDIR)%.o)
CC			=	cc -I$(INCLUDE) #-Wall -Wextra -Werror
RM			=	rm -f
AR			=	ar rcs
NAME		=	so_long

all:		lib $(NAME)

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

.PHONY:		all lib clean fclean re