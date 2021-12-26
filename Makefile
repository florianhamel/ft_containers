# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fhamel <fhamel@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/19 21:04:00 by fhamel            #+#    #+#              #
#    Updated: 2021/12/26 01:16:36 by fhamel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
#####                              FILES VARS                              #####
################################################################################

NAME		=	containers

NAME_		=	ref_containers

D_OBJS		=	objs/

D_SRCS		=	srcs/

_SRC_		=	main.cpp

REFMAIN		=	ref_main.cpp

SRCS		=	$(_SRC_)

OBJS		=	$(addprefix $(D_OBJS), $(_SRC_:.cpp=.o))

OUTFILE1	=	outfile1.txt

OUTFILE2	=	outfile2.txt

################################################################################
#####                           COMPILER OPTIONS                           #####
################################################################################

CC			=	clang++ -std=c++98

FLAGS		=	-Wall -Wextra -Werror

FSANITIZE	=	-g -fsanitize=address

################################################################################
#####                            MAKEFILE RULES                            #####
################################################################################

all	: $(D_OBJS) $(NAME)

$(D_OBJS) :
	@mkdir -p $@

$(D_OBJS)%.o : %.cpp
	$(CC) $(FLAGS) -c $< -o $@

$(NAME) : $(OBJS)
	$(CC) $(FSANITIZE) $(FLAGS) $(OBJS) -o $(NAME)
	$(CC) $(FLAGS) $(REFMAIN) -o $(NAME_)

compare : $(D_OBJS) $(NAME)
	./$(NAME) > $(OUTFILE1)
	./$(NAME_) > $(OUTFILE2)
	diff $(OUTFILE1) $(OUTFILE2)

recompare : re compare

clean :
	rm -rf $(D_OBJS)

fclean : clean
	rm -rf $(NAME)
	rm -rf $(NAME_)
	rm -rf $(OUTFILE1) $(OUTFILE2)

re : fclean all
