RM 		:= rm -rf
LDFLAGS 	+= -Llib
CFLAGS		+= -std=c99 -Iinclude -Wall -Wextra -g -c
SRCS		:= $(wildcard ./*.c)
OBJS		:= $(SRCS:.c=.o)
LIB_NAME	:= libftprintf.a

printf: 	fclean $(OBJS)
			@$(CC) $(CCFLAGS) $(OBJS) $(LDFLAGS) -o a.out

all:		fclean $(OBJS)
			@$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o a.out

fclean:
			$(RM) $(OBJS) $(LIB_NAME)

