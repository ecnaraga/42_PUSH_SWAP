# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: galambey <galambey@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/19 11:53:51 by galambey          #+#    #+#              #
#    Updated: 2023/07/07 13:16:25 by galambey         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= push_swap
CC 			= cc
CFLAGS 		= -Wall -Wextra -Werror
PATH_LIBFT 	= ./libft
INC_LIBFT 	= ./libft/megalibft.a

################################### SOURCES ###################################

MOVE_DIR         	=   move/
MOVE_SRCS        	=   push.c \
	   					reverse_rotate.c \
	   					rotate.c \
	   					swap.c

PARSING_DIR       	=   parsing/
PARSING_SRCS      	=   make_container_a.c \
	   					set_index.c

PUSH_SWAP_DIR       =   push_swap/
PUSH_SWAP_SRCS      =   push_swap.c

SORT_DIR     		=   sort/
SORT_SRCS    		=   sort_five_or_less.c \
	   					sort.c \
	   					which_move.c

UTILS_DIR       	=   utils/
UTILS_SRCS      	=   ft_atoi_mode_only_digit.c \
	   					lst_utils.c \
	   					free.c

BONUS_DIR			=	bonus/
BONUS_SRCS			=	checker.c

############################# HANDLE DIRECTORIES ##############################

SRCS_DIR          		=     srcs/

SRCS					=	$(addprefix $(MOVE_DIR), $(MOVE_SRCS)) \
							$(addprefix $(PARSING_DIR), $(PARSING_SRCS)) \
							$(addprefix $(PUSH_SWAP_DIR), $(PUSH_SWAP_SRCS)) \
							$(addprefix $(SORT_DIR), $(SORT_SRCS)) \
							$(addprefix $(UTILS_DIR), $(UTILS_SRCS))
SRCS_BONUS				=	$(addprefix $(MOVE_DIR), $(MOVE_SRCS)) \
							$(addprefix $(PARSING_DIR), $(PARSING_SRCS)) \
							$(addprefix $(UTILS_DIR), $(UTILS_SRCS)) \
							$(addprefix $(BONUS_DIR), $(BONUS_SRCS))

OBJS_DIR 				= 	.objs/

OBJS_NAMES 				= 	$(SRCS:.c=.o)
OBJS_BONUS_NAMES 		= 	$(SRCS_BONUS:.c=.o)

OBJS_FOLDER				=	$(addprefix $(OBJS_DIR), $(MOVE_DIR) \
                		        $(PARSING_DIR) \
                		        $(PUSH_SWAP_DIR) \
                		        $(SORT_DIR) \
                		        $(BONUS_DIR)\
                		        $(UTILS_DIR))

OBJS					= $(addprefix $(OBJS_DIR), $(OBJS_NAMES))
OBJS_BONUS				= $(addprefix $(OBJS_DIR), $(OBJS_BONUS_NAMES))

DEPS 		:= $(OBJS:.o=.d)
DEPS_BONUS 	:= $(OBJS_BONUS:.o=.d)

#################################### RULES ####################################

all: $(NAME)

$(OBJS_DIR)%.o:$(SRCS_DIR)%.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	make -C ./libft
	$(CC) $(CFLAGS) $(OBJS) $(INC_LIBFT) -o $@

bonus : checker

checker : $(OBJS_BONUS)
	make -C ./libft
	$(CC) $(CFLAGS) $(OBJS_BONUS) $(INC_LIBFT) -o $@

clean:
	make clean -C $(PATH_LIBFT)
	rm -rf $(OBJS_DIR) ./src_bonus/*.o

fclean: clean
	make fclean -C $(PATH_LIBFT)
	rm -f push_swap checker

re: fclean 
	make all

.PHONY: all bonus clean fclean re
	