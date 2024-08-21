NAME = libftprintf.a

CC = cc
FLAGS = -Wall -Wextra -Werror
AR = ar -rcs 

SRC = ft_printf.c ft_putchar.c ft_putstr.c \
      ft_put_hex.c ft_put_ptr.c ft_putnbr.c \
      ft_put_unsigned.c


HEADERS = ft_printf.h

OBJ = $(SRC:.c=.o)

LIBFT_DIR = libft

all: $(NAME) 

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

%.o: %.c $(HEADERS)
	$(CC) $(FLAGS) -c $< -o $@

clean : 
	rm -f $(OBJ)

fclean : 
	rm -f $(NAME) $(OBJ)

re : fclean all

libft:
	$(MAKE) -C $(LIBFT_DIR)

.PHONY: all clean fclean re bonus libft