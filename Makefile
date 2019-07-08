# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anorman <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/21 16:00:27 by anorman           #+#    #+#              #
#    Updated: 2019/07/08 15:00:00 by anorman          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Werror -Wextra
NAME = libft.a
FILES = ft_pushswap_lst.c ft_checker_main.c ft_checker_avs.c\
		ft_pushswap.c

OBJ = $(FILES:%.c=%.o)
OBJDIR = objects

LIBA = -L libft/ -lft
MLIBA = make -C libft

all: $(NAME)

$(NAME):
	$(MLIBA) re
	@gcc -c $(FLAGS) $(FILES)
	@echo "gcc -c $(FLAGS) FILES"
	@ar -rcs $(NAME) $(OBJ)
	@echo "ar -rcs $(NAME) OBJ"
	@gcc -o checker $(OBJ) $(LIBA)

clean:
	@rm -rf $(OBJ)
	@echo "rm -rf OBJ"
	$(MLIBA) clean

fclean: clean
	rm -f $(NAME)
	$(MLIBA) fclean

re: fclean all

debug:
	@gcc -o checker $(FILES)\
		$(LIBA) -g -I libft/includes
