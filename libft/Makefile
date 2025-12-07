CC=cc
NAME = libft.a
SRC_DIR = src/

SRC_CHAINED = $(SRC_DIR)chained_list/ft_lstadd_back_bonus.c \
	$(SRC_DIR)chained_list/ft_lstadd_front_bonus.c \
	$(SRC_DIR)chained_list/ft_lstdelone_bonus.c \
	$(SRC_DIR)chained_list/ft_lstclear_bonus.c \
	$(SRC_DIR)chained_list/ft_lstmap_bonus.c \
	$(SRC_DIR)chained_list/ft_lstiter_bonus.c \
	$(SRC_DIR)chained_list/ft_lstnew_bonus.c \
	$(SRC_DIR)chained_list/ft_lstsize_bonus.c \

SRC_CHAR = $(SRC_DIR)char/ft_isalnum.c \
	$(SRC_DIR)char/ft_isalpha.c \
	$(SRC_DIR)char/ft_isascii.c \
	$(SRC_DIR)char/ft_isdigit.c \
	$(SRC_DIR)char/ft_isprint.c \
	$(SRC_DIR)char/ft_isspace.c \
	$(SRC_DIR)char/ft_tolower.c \
	$(SRC_DIR)char/ft_toupper.c \

SRC_MEMORY = $(SRC_DIR)memory/ft_bzero.c \
	$(SRC_DIR)memory/ft_calloc.c \
	$(SRC_DIR)memory/ft_memchr.c \
	$(SRC_DIR)memory/ft_memcmp.c \
	$(SRC_DIR)memory/ft_memmove.c \
	$(SRC_DIR)memory/ft_memset.c \

SRC_STRING = $(SRC_DIR)string/ft_atoi.c \
	$(SRC_DIR)string/ft_itoa.c \
	$(SRC_DIR)string/ft_split.c \
	$(SRC_DIR)string/ft_strchr.c \
	$(SRC_DIR)string/ft_strrchr.c \
	$(SRC_DIR)string/ft_strdup.c \
	$(SRC_DIR)string/ft_strndup.c \
	$(SRC_DIR)string/ft_striteri.c \
	$(SRC_DIR)string/ft_strmapi.c \
	$(SRC_DIR)string/ft_strjoin.c \
	$(SRC_DIR)string/ft_strlcat.c \
	$(SRC_DIR)string/ft_strlcpy.c \
	$(SRC_DIR)string/ft_strlen.c \
	$(SRC_DIR)string/ft_strncmp.c \
	$(SRC_DIR)string/ft_strnstr.c \
	$(SRC_DIR)string/ft_strtrim.c \
	$(SRC_DIR)string/ft_substr.c \

SRC_WRITE = $(SRC_DIR)write/ft_putstr_fd.c \
	$(SRC_DIR)write/ft_putendl_fd.c \
	$(SRC_DIR)write/ft_putnbr_fd.c \
	$(SRC_DIR)write/ft_putstr_fd.c \

SRC_PRINTF = $(SRC_DIR)ft_printf/converters/lltoa.c \
	$(SRC_DIR)ft_printf/converters/ulltoa.c \
	$(SRC_DIR)ft_printf/converters/xtoa.c \
	$(SRC_DIR)ft_printf/utils/printing_utils.c \
	$(SRC_DIR)ft_printf/ft_printf.c \

SRC_DICT = $(SRC_DIR)dict/ft_dict_clear.c \
	$(SRC_DIR)dict/ft_dict_clear_node.c \
	$(SRC_DIR)dict/ft_dict_get.c \
	$(SRC_DIR)dict/ft_dict_get_node.c \
	$(SRC_DIR)dict/ft_dict_new.c \
	$(SRC_DIR)dict/ft_dict_new_node.c \
	$(SRC_DIR)dict/ft_dict_set.c \
	$(SRC_DIR)dict/ft_dict_unset.c \

SRC_UTILS = $(SRC_DIR)utils/free_2d.c \

SRCS = $(SRC_CHAINED) \
	$(SRC_CHAR) \
	$(SRC_STRING) \
	$(SRC_WRITE) \
	$(SRC_MEMORY) \
	$(SRC_PRINTF) \
	$(SRC_DICT) \
	$(SRC_UTILS) \

OBJ_DIR = .build/
OBJS = $(SRCS:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

CFLAGS = -Wall -Werror -Wextra -g \
		-I include \

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	@echo ""
	@echo "================================"
	@echo "Creating libft..."
	@echo "================================"
	@echo ""
	ar rcs $(NAME) $(OBJS)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)write
	@mkdir -p $(OBJ_DIR)string
	@mkdir -p $(OBJ_DIR)memory
	@mkdir -p $(OBJ_DIR)char
	@mkdir -p $(OBJ_DIR)chained_list
	@mkdir -p $(OBJ_DIR)dict
	@mkdir -p $(OBJ_DIR)utils
	@mkdir -p $(OBJ_DIR)ft_printf
	@mkdir -p $(OBJ_DIR)ft_printf/converters
	@mkdir -p $(OBJ_DIR)ft_printf/utils
	@$(CC) $(CFLAGS) $< -c -o $@

fclean: clean
	@rm -f $(NAME)

clean:
	@rm -rf $(OBJ_DIR)

re: fclean all

.PHONY: all fclean clean re
