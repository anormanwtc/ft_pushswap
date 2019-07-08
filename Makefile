# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anorman <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/21 16:00:27 by anorman           #+#    #+#              #
#    Updated: 2019/07/08 11:27:53 by anorman          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Werror -Wextra
NAME = libft.a
FILES = ft_pushswap_lst.c ft_checker_main.c ft_checker_avs.c\
		ft_pushswap.c

OBJ = $(FILES:%.c=%.o)

LIBA = libft/libft.a
MLIBA = make -C libft

all: $(NAME)

$(NAME):
	$(MLIBA) re
	@gcc -c $(FLAGS) $(FILES) #$(LIBA)
	@echo "gcc -c $(FLAGS) FILES"
	mkdir -p $(OBJDIR)
	@mv $(OBJ) $(OBJDIR)
	@echo "mv OBJ $(OBJDIR)"
	@ar -rcs $(NAME) $(OBJ:%=$(OBJDIR)/%)
	@echo "ar -rcs $(NAME) OBJ"

clean:
	rm -rf $(OBJDIR)
	$(MLIBA) clean

fclean: clean
	rm -f $(NAME)
	$(MLIBA) fclean

re: fclean all
