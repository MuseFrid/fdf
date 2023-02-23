# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gduchesn <gduchesn@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/22 21:45:24 by gduchesn          #+#    #+#              #
#    Updated: 2023/02/23 16:37:22 by gduchesn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

###### Utils ######

CC = gcc
FLAGS = -Wall -Werror -Wextra
LIBRARIES = -lmlx -lm -L$(MINILIBX_DIRECTORY) -framework OpenGL -framework AppKit
INCLUDES = -I$(HEADERS_DIRECTORY) -I$(MINILIBX_HEADERS)
REMOVE = rm -Rf
.PHONY: all clean fclean re

###### color ######

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

###################

HEADERS_LIST = fdf.h \
			   get_next_line.h \
			   lst.h \
			   lst_to_tab.h \
			   macro_key.h \
			   parsing.h \
			   real.h
HEADERS_DIRECTORY = ./include/
HEADERS = $(addprefix $(HEADERS_DIRECTORY), $(HEADERS_LIST))

MINILIBX = $(MINILIBX_DIRECTORY)libmlx.a
MINILIBX_DIRECTORY = ./minilibx_macos/
MINILIBX_HEADERS = $(MINILIBX_DIRECTORY)

SOURCES_DIRECTORY = ./sources/
SOURCES_LIST  = 	get_next_line.c \
					get_next_line_utils.c \
					lstadd_back.c \
					lstclear.c \
					lstlast.c \
					lstnew.c \
					lstsize.c \
					opening.c \
					user_error.c \
					is_fdf.c \
					main.c \
					ft_strncmp.c \
					ft_atoi.c \
					ft_isdigit.c \
					go_int.c \
					map_init.c \
					value_iso.c \
					lign.c
SOURCES = $(addprefix $(SOURCES_DIRECTORY), $(SOURCES_LIST))

OBJECTS_DIRECTORY = objects/
OBJECTS_LIST = $(patsubst %.c, %.o, $(SOURCES_LIST))
OBJECTS = $(addprefix $(OBJECTS_DIRECTORY), $(OBJECTS_LIST))


all: $(NAME)

$(NAME): $(MINILIBX) $(OBJECTS_DIRECTORY) $(OBJECTS)
	$(CC) $(FLAGS) $(LIBRARIES) $(INCLUDES) $(OBJECTS) -o $(NAME)

$(OBJECTS_DIRECTORY):
	mkdir -p $(OBJECTS_DIRECTORY)

$(OBJECTS_DIRECTORY)%.o : $(SOURCES_DIRECTORY)%.c $(HEADERS)
	$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@

$(MINILIBX):
	$(MAKE) -C $(MINILIBX_DIRECTORY)

clean:
	$(MAKE) -C $(MINILIBX_DIRECTORY) clean
	$(REMOVE) $(OBJECTS_DIRECTORY)

fclean: clean
	$(REMOVE) $(MINILIBX)
	$(REMOVE) $(NAME)

re: fclean all
