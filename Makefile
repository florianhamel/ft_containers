# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fhamel <fhamel@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/19 21:04:00 by fhamel            #+#    #+#              #
#    Updated: 2021/12/12 12:28:04 by fhamel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
#####                              FILES VARS                              #####
################################################################################

NAME		=	containers

NAME_		=	ref_containers

D_OBJS		=	objs/

D_SRCS		=	srcs/

_SRC_		=	main.cpp \

REFMAIN		=	ref_main.cpp \

SRCS		=	$(_SRC_)

OBJS		=	$(addprefix $(D_OBJS), $(_SRC_:.cpp=.o))

################################################################################
#####                           COMPILER OPTIONS                           #####
################################################################################

CC			=	clang++ -std=c++98

FLAGS		=	-Wall -Wextra -Werror

FSANITIZE	=	-g -fsanitize=address

################################################################################
#####                            MAKEFILE RULES                            #####
################################################################################

all	: $(D_OBJS) $(LIBFT) $(NAME)

bonus : $(D_OBJS) $(LIBFT) $(NAME_B)

$(D_OBJS) :
	@mkdir -p $@

$(D_OBJS)%.o : %.cpp
	$(CC) $(FLAGS) -c $< -o $@

$(NAME) : $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)
	$(CC) $(FLAGS) $(REFMAIN) -o $(NAME_)

clean :
	rm -rf $(D_OBJS)

fclean : clean
	rm -rf $(NAME)
	rm -rf $(NAME_)

re : fclean all
