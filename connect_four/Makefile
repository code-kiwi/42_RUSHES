# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/06 23:47:34 by mhotting          #+#    #+#              #
#    Updated: 2024/09/06 23:58:58 by mhotting         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#################################################
#              Variable definitions             #
#################################################

# GENERAL
NAME					=	connect4
CC						=	cc
ifndef NOFLAGS
	CFLAGS				=	-Wall -Werror -Wextra
endif
HFLAGS					=	-I$(HEADERS_DIR) -I$(LIBFT_HEADERS_DIR)
FSFLAGS					=	-fsanitize=address

# HEADERS
HEADERS_DIR				=	includes/
HEADERS_FILES			=	connect_four.h
HEADERS					=	$(addprefix $(HEADERS_DIR), $(HEADERS_FILES))

# LIBFT
LIBFT_DIR				=	libft/
LIBFT_FILE				=	libft.a
LIBFT					=	$(addprefix $(LIBFT_DIR), $(LIBFT_FILE))
LIBFT_HEADERS_SUBDIR	=	includes/
LIBFT_HEADERS_DIR		=	$(addprefix $(LIBFT_DIR), $(LIBFT_HEADERS_SUBDIR))
LIBFT_HEADERS_FILE		=	libft.h
LIBFT_HEADERS			=	$(addprefix $(LIBFT_HEADERS_DIR), $(LIBFT_HEADERS_FILE))
LIBFT_FLAGS				=	-L$(LIBFT_DIR) -lft 

# MAIN
MAIN_DIR				=	main/
MAIN_FILE				=	main.c
MAIN					=	$(addprefix $(MAIN_DIR), $(MAIN_FILE))

# SOURCES GENERAL
SRCS_MAIN_DIR			=	srcs/
SRCS_FILES				=	$(MAIN)
SRCS					=	$(addprefix $(SRCS_MAIN_DIR), $(SRCS_FILES))

# OBJECTS GENERAL
OBJS_MAIN_DIR			=	objs/
OBJS_FILES				=	$(SRCS_FILES:.c=.o)
OBJS					=	$(addprefix $(OBJS_MAIN_DIR), $(OBJS_FILES))

# DEPENDENCIES
DEPS_MAIN_DIR			=	deps/
DEPS_FILES				=	$(OBJS_FILES:.o=.d)
DEPS					=	$(addprefix $(DEPS_MAIN_DIR), $(DEPS_FILES))

#################################################
#               Rule definitions                #
#################################################

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(HFLAGS) $(OBJS) $(LIBFT_FLAGS) -o $@

$(OBJS_MAIN_DIR)%.o: $(SRCS_MAIN_DIR)%.c $(HEADERS) $(LIBFT_HEADERS)
	@mkdir -p $(@D)
	@mkdir -p $(DEPS_MAIN_DIR)$(dir $*)
	$(CC) $(CFLAGS) $(HFLAGS) -MP -MMD -MF $(DEPS_MAIN_DIR)$*.d -c $< -o $@ 

$(LIBFT): init_submodule FORCE
	$(MAKE) -sC $(LIBFT_DIR)

FORCE:

fsanitize: fclean $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(HFLAGS) $(FSFLAGS) $(OBJS) $(LIBFT_FLAGS) -o $(NAME)

init_submodule:
	@if git submodule status | egrep -q '^[-+]' ; then \
		echo "*Info: Need to initialize git submodules"; \
		git submodule update --init; \
	fi

-include $(DEPS)

clean:
	rm -rf $(OBJS_MAIN_DIR)
	rm -rf $(DEPS_MAIN_DIR)

clean-libft:
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)

fclean-libft:
	$(MAKE) -sC $(LIBFT_DIR) fclean

ffclean: fclean fclean-libft

re: fclean all

rre: ffclean re

.PHONY: all clean fclean re clean-libft fclean-libft ffclean rre FORCE fsanitize init_submodule