NAME = libft.a

INCLUDES = ./

SRCS =  ft_strlen.c ft_strdup.c ft_strjoin.c ft_strchr.c ft_strncmp.c \
		ft_isdigit.c ft_split.c ft_strlcpy.c get_next_line.c

OBJS = $(SRCS:%.c=%.o)

HEADER = libft.h

COMPILE = gcc -Wall -Wextra -Werror


all: $(NAME)

$(NAME): $(OBJS) $(HEADER)
	ar rcs $(NAME) $(OBJS)
	ranlib $(NAME)

%.o: %.c
	gcc -c -Wall -Wextra -Werror -I $(INCLUDES) -o $@ $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
