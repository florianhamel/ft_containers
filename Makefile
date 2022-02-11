# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fhamel <fhamel@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/28 18:43:03 by fhamel            #+#    #+#              #
#    Updated: 2022/02/11 03:01:45 by fhamel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
#####                              FILES VARS                              #####
################################################################################

NAME		=	ft_containers

NAME_		=	ref_ft_containers

NAME_BONUS	=	set

NAME_BONUS_	=	ref_set

NAME_RAND	=	tree_random

D_OBJS		=	objs/

D_SRCS		=	srcs/

INCLUDES	=	includes/

_SRC_		=	main.cpp \
				ref_main.cpp \
				main_bonus.cpp \
				ref_main_bonus.cpp \
				main_random_bonus.cpp \

SRCS		=	$(addprefix $(D_SRCS), $(_SRC_))

OBJS		=	$(addprefix $(D_OBJS), $(_SRC_:.cpp=.o))clear


R			=	\033[0;31m
G			=	\033[0;32m
B			=	\033[0;34m
W			=	\033[0m

################################################################################
#####                           COMPILER OPTIONS                           #####
################################################################################

CC			=	clang++ -std=c++98

FLAGS		=	-Wall -Wextra -Werror

FSANITIZE	=	-g -fsanitize=address

################################################################################
#####                            MAKEFILE RULES                            #####
################################################################################

all	: $(NAME)

$(D_OBJS)%.o : $(D_SRCS)%.cpp Makefile
	@$(CC) $(FLAGS) -c $< -o $@ -I$(INCLUDES)
	@printf "$(B)$<$(W) linking...\n"

$(NAME) : $(D_OBJS)main.o Makefile
	@$(CC) $(D_OBJS)main.o -o $(NAME)
	@printf "[ $(G)$(NAME)$(W) ] compiled\n"

ref_main : $(D_OBJS)ref_main.o Makefile
	@$(CC) $(D_OBJS)ref_main.o -o $(NAME_)
	@printf "[ $(G)$(NAME_)$(W) ] compiled\n"

set : $(D_OBJS)main_bonus.o Makefile
	@$(CC) $(D_OBJS)main_bonus.o -o $(NAME_BONUS)
	@printf "[ $(G)$(NAME_BONUS)$(W) ] compiled\n"

ref_set : $(D_OBJS)ref_main_bonus.o Makefile
	@$(CC) $(D_OBJS)ref_main_bonus.o -o $(NAME_BONUS_)
	@printf "[ $(G)$(NAME_BONUS_)$(W) ] compiled\n"

tree_random : $(D_OBJS)main_random_bonus.o Makefile
	@$(CC) $(D_OBJS)main_random_bonus.o -o $(NAME_RAND)
	@printf "[ $(G)$(NAME_RAND)$(W) ] compiled\n"

compare :
	./$(NAME) > ft_file
	./$(NAME_) > std_file
	diff ft_file std_file

compare_bonus :
	./$(NAME_BONUS) > ft_file
	./$(NAME_BONUS_) > std_file
	diff ft_file std_file

clean :
	@rm -rf $(D_OBJS)*.o
	@printf "[ objects ] $(R)removed\n$(W)"

fclean : clean
	@rm -rf $(NAME)
	@printf "[ $(NAME) ] $(R)removed\n$(W)"
	@rm -rf $(NAME_)
	@printf "[ $(NAME_) ] $(R)removed\n$(W)"
	@rm -rf $(NAME_BONUS)
	@printf "[ $(NAME_BONUS) ] $(R)removed\n$(W)"
	@rm -rf $(NAME_BONUS_)
	@printf "[ $(NAME_BONUS_) ] $(R)removed\n$(W)"
	@rm -rf $(NAME_RAND)
	@printf "[ $(NAME_RAND) ] $(R)removed\n$(W)"
	@rm -rf ft_file std_file
	@printf "[ ft_file ] [ std_file ] $(R)removed\n$(W)"

re : fclean all
