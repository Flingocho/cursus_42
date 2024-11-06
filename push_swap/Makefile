SRCS		=	push_swap.c rotate.c rev_rotate.c sort_3.c \
				push.c swap.c stack_init.c handle_errors.c \
				init_a_to_b.c init_b_to_a.c stack_utils.c \
				sort_stacks.c push_swap_utils.c
SRCS_BONUS	=	rotate.c rev_rotate.c sort_3.c \
				push.c swap.c stack_init.c handle_errors.c \
				init_a_to_b.c init_b_to_a.c stack_utils.c \
				sort_stacks.c push_swap_utils.c
INCLUDE		=	include
LIBFT		=	libft
FTPRINTF	=	ftprintf
OBJDIR		=	objs/
OBJS		=	$(SRCS:%.c=$(OBJDIR)%.o)
OBJS_BONUS	=	$(SRCS_BONUS:%.c=$(OBJDIR)%.o)
CC			=	cc -I$(INCLUDE) -Wall -Wextra -Werror
RM			=	rm -f
AR			=	ar rcs
NAME		=	push_swap
BONUS		=	checker

all:		lib $(NAME)

bonus:		lib $(NAME)
			$(CC) checker.c $(OBJS_BONUS) -L$(LIBFT) -lft -o $(BONUS)

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
			$(RM) $(BONUS)
			make -C $(LIBFT) fclean

re:			fclean all


.PHONY:		all lib clean fclean re bonus 
