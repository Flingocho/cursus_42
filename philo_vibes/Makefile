SRCS		=	philo.c
INCLUDE		=	include
LIBFT		=	libft
OBJDIR		=	objs/
OBJS		=	$(SRCS:%.c=$(OBJDIR)%.o)
CC			=	cc -I$(INCLUDE) -Wall -Wextra -Werror
RM			=	rm -f
AR			=	ar rcs
NAME		=	philo

all:		lib $(NAME)

lib:
			make -C $(LIBFT)

$(NAME):	$(OBJS)
			make -C $(LIBFT)
			$(CC) $(OBJS) -L$(LIBFT) -lft -lpthread -o $(NAME)

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


.PHONY:		all lib clean fclean re 