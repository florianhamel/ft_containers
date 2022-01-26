# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fhamel <fhamel@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/19 21:04:00 by fhamel            #+#    #+#              #
#    Updated: 2022/01/26 19:07:43 by fhamel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
#####                              FILES VARS                              #####
################################################################################

NAME		=	containers

NAME_		=	ref_containers

NAME_BONUS	=	set

NAME_BONUS_	=	ref_set

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

all	: $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(FSANITIZE) $(FLAGS) main.cpp -o $(NAME)
	$(CC) $(FLAGS) ref_main.cpp -o $(NAME_)

compare :
	./$(NAME) > $(OUTFILE1)
	./$(NAME_) > $(OUTFILE2)
	diff $(OUTFILE1) $(OUTFILE2)

recompare : re compare

bonus :
	$(CC) $(FLAGS) main_bonus.cpp -o $(NAME_BONUS)
	$(CC) $(FLAGS) ref_main_bonus.cpp -o $(NAME_BONUS_)

compare_bonus : 
	./$(NAME_BONUS) > $(OUTFILE1)
	./$(NAME_BONUS_) > $(OUTFILE2)
	diff $(OUTFILE1) $(OUTFILE2)

recompare_bonus : fclean bonus compare_bonus

diff :
	diff $(OUTFILE1) $(OUTFILE2)

clean :
	rm -rf $(D_OBJS)

fclean : clean
	rm -rf $(NAME)
	rm -rf $(NAME_)
	rm -rf $(NAME_BONUS)
	rm -rf $(NAME_BONUS_)
	rm -rf $(OUTFILE1) $(OUTFILE2)

re : fclean all
