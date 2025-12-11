CC=cc
NAME = philo
SRC_DIR = src/


SRCS = $(SRC_DIR)philo.c \
	$(SRC_DIR)main.c \
	$(SRC_DIR)utils.c \
	$(SRC_DIR)time.c \
	$(SRC_DIR)init.c \

OBJ_DIR = .build/
OBJS = $(SRCS:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

FSANITIZE = -fsanitize=undefined,thread -fno-omit-frame-pointer \

CFLAGS = -Wall -Werror -Wextra -g \
		-I include \
		-I libft/include \
		-pthread

LDFLAGS = -pthread

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

$(NAME): $(OBJS)
	@echo ""
	@echo "================================"
	@echo "Creating philosopher..."
	@echo "================================"
	@echo ""
	@$(CC) $(OBJS) $(LDFLAGS) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $< -c -o $@

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_BONUS)

clean:
	rm -rf $(OBJ_DIR)

re: fclean all

.PHONY: all fclean clean re
