# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/25 14:34:04 by fcoullou          #+#    #+#              #
#    Updated: 2024/04/26 18:19:07 by fcoullou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
##	PROGS NAMES ################################################################
NAME			= push_swap	
BONUS			= checker						

################################################################################
##	PATHS ######################################################################
SRC_PATH		= src
INC_PATH		= include
OBJ_PATH		= obj
BONUS_PATH		= bonus
LIBFT			= ./libft

################################################################################
##	FILES ######################################################################
SRC				= $(SRC_PATH)/errors/errors.c \
				$(SRC_PATH)/errors/parsing.c \
				$(SRC_PATH)/main/main.c \
				$(SRC_PATH)/rules/push.c \
				$(SRC_PATH)/rules/reverse.c \
				$(SRC_PATH)/rules/rotate.c \
				$(SRC_PATH)/rules/swap.c \
				$(SRC_PATH)/sort/cost2.c \
				$(SRC_PATH)/sort/costs.c \
				$(SRC_PATH)/sort/methods_a2b.c \
				$(SRC_PATH)/sort/methods_b2a.c \
				$(SRC_PATH)/sort/sorting.c \
				$(SRC_PATH)/utils/utils.c \
				$(SRC_PATH)/utils/utils2.c \
				$(SRC_PATH)/utils/utils3.c \
#------------------------------------------------------------------------------#
SRC_BONUS		= $(BONUS_PATH)/main.c \
				$(SRC_PATH)/errors/errors.c \
				$(SRC_PATH)/errors/parsing.c \
				$(SRC_PATH)/rules/push.c \
				$(SRC_PATH)/rules/reverse.c \
				$(SRC_PATH)/rules/rotate.c \
				$(SRC_PATH)/rules/swap.c \
				$(SRC_PATH)/sort/cost2.c \
				$(SRC_PATH)/utils/utils.c \
				$(SRC_PATH)/utils/utils2.c \
				$(SRC_PATH)/utils/utils3.c \
#------------------------------------------------------------------------------#
INC				= $(INC_PATH)/bonus.h \
				$(INC_PATH)/push_swap.h \
#------------------------------------------------------------------------------#
OBJ				= $(SRC:$(SRC_PATH)%.c=$(OBJ_PATH)%.o)
OBJ_BONUS		= $(SRC_BONUS:$(BONUS_PATH)%.c=$(OBJ_PATH)%.o)
#------------------------------------------------------------------------------#
OUTPUT_LEAKS 	= valgrind-out.txt

################################################################################
##	COMPILER ###################################################################
CFLAGS			= -Wall -Werror -Wextra -I./include -I./libft/include -g3
LFLAGS 			=  -L./libft -lft
#------------------------------------------------------------------------------#
AR				= ar
CC				= cc
RM				= rm -f
CD				= cd
DIR_DUP			= mkdir -p $(@D)

################################################################################
##	RULES ######################################################################
all: $(NAME)

$(NAME): $(OBJ) $(INC)
	@make -C $(LIBFT)
	@printf "CREATED $@\n"
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LFLAGS) 
	@printf "CREATED $@"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@$(DIR_DUP)
	$(CC) $(CFLAGS) -c $< -o $@ 
#------------------------------------------------------------------------------#
bonus: $(BONUS)
	
$(BONUS): $(OBJ_BONUS) $(INC)
	@make -C $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ_BONUS) -o $(BONUS) $(LFLAGS)
	@printf "CREATED $@\n"
		
$(OBJ_PATH)/%.o: $(BONUS_PATH)/%.c
	@$(DIR_DUP)
	$(CC) $(CFLAGS) -c $< -o $@
	@printf "CREATED $@\n"
#------------------------------------------------------------------------------#
clean:
	make -C $(LIBFT) clean
	$(RM) $(OBJ)
	$(RM) -r $(OBJ_PATH)
	$(RM) -r $(LIBFT_OBJ)
#------------------------------------------------------------------------------#
fclean: clean
	make -C $(LIBFT) fclean
	$(RM) $(NAME)
	$(RM) $(BONUS)
	$(RM) -r $(OBJ_PATH)
#------------------------------------------------------------------------------#
re: fclean all
#------------------------------------------------------------------------------#
test: all
	./$(NAME)
#------------------------------------------------------------------------------#
leaks: all
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=$(OUTPUT_LEAKS) ./$(NAME)
	@cat valgrind-out.txt
#------------------------------------------------------------------------------#
.PHONY: all bonus clean fclean re test leaks  
#------------------------------------------------------------------------------#
