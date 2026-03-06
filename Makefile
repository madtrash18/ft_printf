NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar
HEADER = ./

SRCS = ./ft_printf.c ./ft_printf_unsignednum.c ./ft_printf_intnum.c\
./ft_printf_string.c ./ft_printf_hexauppernum.c ./ft_printf_hexalowernum.c\
./ft_printf_pointer.c

OBJS = $(SRCS:.c=.o)


all : $(NAME)

$(NAME) : $(OBJS)
	$(AR) -rcs $(NAME) $^

%.o : %.c
	$(CC) $(CFLAGS) -c $^

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re


# -I$(HEADER)
