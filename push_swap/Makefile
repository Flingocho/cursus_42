SRCS		=	push_swap.c rotate.c rev_rotate.c sort_3.c \
				push.c swap.c stack_init.c handle_errors.c \
				init_a_to_b.c init_b_to_a.c stack_utils.c \
				sort_stacks.c
INCLUDE		=	include
LIBFT		=	libft
FTPRINTF	=	ftprintf
OBJDIR		=	objs/
OBJS		=	$(SRCS:%.c=$(OBJDIR)%.o)
CC			=	cc -I$(INCLUDE) -Wall -Wextra -Werror
RM			=	rm -f
AR			=	ar rcs
NAME		=	push_swap

all:		lib $(NAME)

bonus:		lib $(NAME)

lib:
			make -C $(LIBFT)

$(NAME):	$(OBJS)
			make -C $(LIBFT)
			$(CC) $(OBJS) -L$(LIBFT) -lft -o $(NAME)

$(OBJDIR)%.o: %.c
			mkdir -p $(OBJDIR)
			$(CC) -c $< -o $@

clean:
			$(RM) $(OBJS)
			rm -rf $(OBJDIR)
			make -C  $(LIBFT) clean

fclean:		clean
			$(RM) $(NAME)
			make -C $(LIBFT) fclean

re:			fclean all

.PHONY:		all lib clean fclean re bonus 
