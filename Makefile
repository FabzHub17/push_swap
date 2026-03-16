NAME = push_swap

LIBFT_PATH=libft
LIBFT = $(LIBFT_PATH)/libft.a
LIBFT_FLAG= -L$(LIBFT_PATH) -lft

CC = cc
RM = rm -f
CFLAGS = -Wall -Werror -Wextra 

SRC = src/push_swap.c src/utils.c src/stack_utils.c \
	  src/stack_sort.c src/stack_init.c src/handle_errors.c \
	  src/operations/push.c src/operations/rotate.c \
	  src/operations/swap.c src/operations/reverse_rotate.c \
	  src/sort_turkish.c src/sort_init_a.c src/sort_init_b.c \
	  src/sort_turkish_utils.c 

OBJECTS = $(SRC:.c=.o)

$(NAME): $(LIBFT) $(OBJECTS)
		@$(CC) $(CFLAGS) -o $@ $^ $(LIBFT_FLAG)
		@echo "$(NAME) OK!"

$(LIBFT):
		@$(MAKE) --no-print-directory -C $(LIBFT_PATH)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean: 
		@$(RM) $(OBJECTS)
		@$(MAKE) --no-print-directory -C $(LIBFT_PATH) clean

fclean: clean
	@$(RM) $(NAME) 
	@$(RM) $(LIBFT)

re: fclean all

.PHONY: all re clean fclean bonus