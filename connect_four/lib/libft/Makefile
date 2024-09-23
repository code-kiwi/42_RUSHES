NAME = libft.a

CFLAGS = -Wall -Werror -Wextra -I$(INCLUDES)

DFLAGS = -MMD -MP

include src.mk

INCLUDES = includes

BUILD_DIR = .build

SRC_DIR = srcs

MY_OBJECT = $(addprefix $(BUILD_DIR)/, $(SRC:.c=.o))

DEPS = $(OBJ:.o=.d)

CC = cc

-include $(DEPS)

.PHONY: all
all : $(NAME)

$(NAME) : $(MY_OBJECT)
	ar rc $(NAME) $(MY_OBJECT)

$(BUILD_DIR)/%.o : $(SRC_DIR)/%.c
	@mkdir -p $(shell dirname $@)
	$(CC) $(CFLAGS) -o $@ -c $<

.PHONY: clean
clean :
	$(RM) -r $(BUILD_DIR)

.PHONY: fclean
fclean : clean
	$(RM) $(NAME)

.PHONY: re
re : fclean all
