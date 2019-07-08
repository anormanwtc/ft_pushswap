# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anorman <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/21 16:00:27 by anorman           #+#    #+#              #
#    Updated: 2019/07/08 17:14:38 by anorman          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Werror -Wextra
NAME = libftpushswap.a
FILES = ft_pushswap_lst.c ft_checker_avs.c\

CHECKER = ft_checker_main.c
PUSHSWAP = ft_pushswap_main.c

OBJ = $(FILES:%.c=%.o)
OBJDIR = objects

LIBA = -L libft/ -lft
MLIBA = make -C libft

all: $(NAME)

$(NAME):
	@$(MLIBA) re
	@echo "compiling libft.a"
	@gcc -c $(FLAGS) $(FILES) $(CHECKER) $(PUSHSWAP)
	@echo "gcc -c $(FLAGS) FILES"
	@ar -rcs $(NAME) $(OBJ)
	@echo "ar -rcs $(NAME) OBJ"
	@gcc -o checker $(OBJ) $(LIBA) $(CHECKER:%.c=%.o)
	@gcc -o pushswap $(OBJ) $(LIBA) $(PUSHSWAP:%.c=%.o)

clean:
	@rm -rf $(OBJ) $(CHECKER:%.c=%.o) $(PUSHSWAP:%.c=%.o)
	@echo "rm -rf OBJ"
	@$(MLIBA) clean
	@echo "make -C libft clean"

fclean: clean
	@echo "make clean"
	rm -f $(NAME)
	$(MLIBA) fclean

re: fclean all

debug:
	@gcc -o checker $(FILES) $(CHECKER)\
		$(LIBA) -g -I libft/includes
