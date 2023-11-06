RM=			rm -f
NAME=		libftprintf.a
CC=			cc
CFLAGS=		-Wall -Wextra -Werror
SRCS_MAN=	ft_printf.c print_num.c print_char_or_addr.c
OBJS_MAN =  $(SRCS_MAN:.c=.o)
.PHONY : all bonus clean fclean re

all : $(NAME)

$(NAME) : $(OBJS_MAN)
	ar rc $(NAME) $(OBJS_MAN)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I./

clean :
	$(RM) $(OBJS_MAN)
	$(RM) $(OBJS_BONUS) 

fclean :
	make clean
	$(RM) $(NAME)

re :
	make fclean
	make all