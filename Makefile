# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anorman <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/21 16:00:27 by anorman           #+#    #+#              #
#    Updated: 2019/07/16 12:12:35 by anorman          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Werror -Wextra
NAME = libftpushswap.a
FILES = ft_stackcreate.c ft_stackinputs.c ft_stackgeneral.c\

CH_MAIN = ft_checker_main.c
PS_MAIN = ft_pushswap_main.c
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
	@gcc -c $(FLAGS) $(FILES) $(CH_MAIN) #$(PS_MAIN)
	@echo "gcc -c $(FLAGS) FILES"
	@ar -rcs $(NAME) $(OBJ)
	@echo "ar -rcs $(NAME) OBJ"
	@gcc -o $(CH_EXE) $(CH_MAIN:%.c=%.o) $(NAME) $(LIBA)
	#@gcc -o $(PS_EXE) $(PS_MAIN:%.c=%.o) $(NAME) $(LIBA)
	@rm -rf $(OBJ) $(CH_MAIN:%.c=%.o) $(PS_MAIN:%.c=%.o)

quick:
	@gcc -o $(CH_EXE) $(CH_MAIN:%.c=%.o) $(NAME) $(LIBA)
	@gcc -o $(PS_EXE) $(PS_MAIN:%.c=%.o) $(NAME) $(LIBA)
	@echo "gcc -o $(CH_EXE) $(CH_MAIN:%.c=%.o) $(NAME) $(LIBA)"
	@echo "gcc -o $(PS_EXE) $(PS_MAIN:%.c=%.o) $(NAME) $(LIBA)"

clean:
	@rm -rf $(OBJ) $(CH_MAIN:%.c=%.o) $(PS_MAIN:%.c=%.o)
	@echo "rm -rf OBJ"
	#@$(MLIBA) fclean
	rm -f $(NAME)
	#@echo "make -C libft fclean"

@clean:
	@rm -rf $(OBJ) $(CH_MAIN:%.c=%.o) $(PS_MAIN:%.c=%.o)
	@#$(MLIBA) fclean
	@rm -f $(NAME)

fclean: @clean
	@echo "make clean"
	rm -rf $(CH_EXE) $(PS_EXE)

re: fclean all

ch_debug:
	@gcc -o $(CH_EXE) $(FILES) $(CH_MAIN)\
		$(LIBA) -g -I libft/includes

ps_debug:
	@gcc -o $(PS_EXE) $(FILES) $(PS_MAIN)\
		$(LIBA) -g -I libft/includes\

