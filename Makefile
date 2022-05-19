# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyna <hyna@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/19 12:17:02 by hyna              #+#    #+#              #
#    Updated: 2022/05/19 17:46:09 by hyna             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
CCFLAGS = -framework OpenGL -framework AppKit
INC_LINK = -I./includes
LIBS = -L./minilibx_opengl_20191021\
	   -L./lib/mlx -lmlx\
	   #-L./lib/libft -lft\

SRCS_NAME = main.c
SRCS_PATH = ./srcs
SRCS = $(addprefix $(SRCS_PATH)/, $(SRCS_NAME))

OBJS_NAME = $(SRCS_NAME:.c=.o)
OBJS_PATH = ./objs
OBJS = $(addprefix $(OBJS_PATH)/, $(OBJS_NAME))

all : $(NAME)

$(NAME) : $(OBJS) 
	$(CC) $(CCFLAGS) $(LIBS) $(FRA_WRK) -o $(NAME) $(OBJS)

$(OBJS_PATH)/%.o : $(SRCS_PATH)/%.c
	@mkdir $(OBJS_PATH) 2> /dev/null || true
	$(CC) $(LIBS) $(CCFLAGS) -c $< -o $@

libft :
	@$(MAKE) -C ./lib/libft all

clean :
	@$(MAKE) -C ./lib/libft clean
	rm -rf $(OBJS_PATH)

fclean : clean
	rm -rf ./lib/libft/libft.a
	rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean
