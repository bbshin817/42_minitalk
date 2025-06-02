SERVER_SRCS	=	src/server.c
SERVER_OBJS	=	$(SERVER_SRCS:.c=.o)

CLIENT_SRCS	=	src/client.c \
				utils/ex_atoi.c
CLIENT_OBJS =	$(CLIENT_SRCS:.c=.o)

OBJS		=	$(SERVER_OBJS) \
				$(CLIENT_OBJS)
SERVER_NAME	=	server
CLIENT_NAME	=	client

PRINTF_DIR = printf
PRINTF_A = $(PRINTF_DIR)/libftprintf.a

CC		= cc
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(LIBFT_A) $(PRINTF_A) client server

client: $(CLIENT_OBJS)
	$(CC) $(CFLAGS) $(CLIENT_OBJS) $(LIBFT_A) $(PRINTF_A) -o $(CLIENT_NAME)

server: $(SERVER_OBJS)
	$(CC) $(CFLAGS) $(SERVER_OBJS) $(LIBFT_A) $(PRINTF_A) -o $(SERVER_NAME)

all: $(NAME)

$(PRINTF_A):
	$(MAKE) -C $(PRINTF_DIR)

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(PRINTF_DIR) clean

fclean:	clean
	$(RM) $(NAME) $(SERVER_NAME) $(CLIENT_NAME)
	$(MAKE) -C $(PRINTF_DIR) fclean

re:	fclean	all

.PHONY:	all clean fclean re