NAME = libftprintf.a

CC = gcc
FLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c \

bonus = 

HEADERS = ft_printf.h

OBJ = $(SRC: .c = .o)

bonus: $(OBJ) # Assuming bonus files are in SRC and HEADERS
	$(AR) $(NAME) $^

AR = ar rcs

all = $(NAME)

$(NAME): $(OBJ)
	$(AR) $@ $^

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean : 
	rm -f $(OBJ)
fclean : 
	rm -f $(NAME) $(HEADERS)

re = fclean all


