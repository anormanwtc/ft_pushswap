# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anorman <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/21 16:00:27 by anorman           #+#    #+#              #
#    Updated: 2019/07/11 14:33:06 by anorman          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Werror -Wextra
NAME = libftpushswap.a
FILES = ft_checker_avs.c ft_pushswap_gen.c\
		ft_pushswap_sort.c ft_pushswap_lst.c

CHECKER = ft_checker_main.c
PUSHSWAP = ft_pushswap_main.c
CH_EXE = checker
PS_EXE = push_swap

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
	@gcc -o $(CH_EXE) $(OBJ) $(LIBA) $(CHECKER:%.c=%.o)
	@gcc -o $(PS_EXE) $(OBJ) $(LIBA) $(PUSHSWAP:%.c=%.o)

clean:
	@rm -rf $(OBJ) $(CHECKER:%.c=%.o) $(PUSHSWAP:%.c=%.o)
	@echo "rm -rf OBJ"
	@$(MLIBA) fclean
	rm -f $(NAME)
	@echo "make -C libft fclean"

fclean: clean
	@echo "make clean"
	rm -rf $(CH_EXE) $(PS_EXE)

re: fclean all

ch_debug:
	@gcc -o $(CH_EXE) $(FILES) $(CHECKER)\
		$(LIBA) -g -I libft/includes

ps_debug:
	@gcc -o $(PS_EXE) $(FILES) $(PUSHSWAP)\
		$(LIBA) -g -I libft/includes libft/srcs/ft_memreplace.c
