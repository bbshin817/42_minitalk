SERVER_SRCS	=	src/server.c
SERVER_OBJS	=	$(SERVER_SRCS:.c=.o)

CLIENT_SRCS	=	src/client.c \
				utils/ex_atoi.c \
				utils/errors.c
CLIENT_OBJS =	$(CLIENT_SRCS:.c=.o)

OBJS		=	$(SERVER_OBJS) \
				$(CLIENT_OBJS)
NAME 		=	client server

PRINTF_DIR = printf
PRINTF_A = $(PRINTF_DIR)/libftprintf.a

CC		= cc
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror

all: $(NAME)

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(PRINTF_A)
	$(MAKE) $@

client: $(CLIENT_OBJS) $(PRINTF_A)
	$(CC) $(CFLAGS) $(CLIENT_OBJS) $(PRINTF_A) -o client

server: $(SERVER_OBJS) $(PRINTF_A)
	$(CC) $(CFLAGS) $(SERVER_OBJS) $(PRINTF_A) -o server

$(PRINTF_A):
	$(MAKE) -C $(PRINTF_DIR)

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(PRINTF_DIR) clean

fclean:	clean
	$(RM) $(NAME)
	$(MAKE) -C $(PRINTF_DIR) fclean

re:	fclean	all

.PHONY:	all clean fclean re