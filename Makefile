CC=cc
NAME = philosopher
SRC_DIR = src/

SRC_INIT = $(SRC_DIR)init/check_args.c \
	$(SRC_DIR)init/init.c \
	$(SRC_DIR)init/init_philosopher.c \

SRC_CLEAR = $(SRC_DIR)clear/clear.c \

SRC_MONI = $(SRC_DIR)routines/threads_monitoring.c \
	$(SRC_DIR)routines/threads_philo.c \

SRC_UTILS = $(SRC_DIR)utils/set_time.c \

SRCS = $(SRC_DIR)philosopher.c \
	$(SRC_INIT) \
	$(SRC_CLEAR) \
	$(SRC_MONI) \
	$(SRC_UTILS) \

OBJ_DIR = .build/
OBJS = $(SRCS:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)
LIBFT = ./libft/libft.a

FSANITIZE = -fsanitize=address,undefined,leak -fno-omit-frame-pointer \
            -fsanitize-recover=address

CFLAGS = -Wall -Werror -Wextra -g \
		-I include \
		-I libft/include \
		-pthread

LDFLAGS = $(LIBFT) -pthread

ifdef SANITIZE
	CFLAGS += $(FSANITIZE)
	LDFLAGS += $(FSANITIZE)
endif

all: $(NAME)

sanitize:
	@echo ""
	@echo "================================"
	@echo "Recompiling with fsanitize flags..."
	@echo "================================"
	@echo ""
	@$(MAKE) re SANITIZE=1

$(NAME): $(OBJS) $(LIBFT)
	@echo ""
	@echo "================================"
	@echo "Creating philosopher..."
	@echo "================================"
	@echo ""
	@$(CC) $(OBJS) $(LDFLAGS) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)init
	@mkdir -p $(OBJ_DIR)clear
	@mkdir -p $(OBJ_DIR)utils
	@mkdir -p $(OBJ_DIR)routines
	@$(CC) $(CFLAGS) $< -c -o $@

$(LIBFT):
	@echo ""
	@echo "================================"
	@echo "Compiling libft objects..."
	@echo "================================"
	@echo ""
	@$(MAKE) -C libft

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_BONUS)
	$(MAKE) -C libft fclean

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C libft clean

re: fclean all

.PHONY: all fclean clean re
