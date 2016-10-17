# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rabougue <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/10 19:16:51 by rabougue          #+#    #+#              #
#    Updated: 2016/09/22 01:49:33 by rabougue         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
#Additional lib : FMOD for sound
#	brew install Caskroom/cask/fmod-studio
################################################################################

####################################_COLOR_#####################################
GREEN = \033[38;5;10m
GREY = \033[38;5;60m
END = \033[0m
##################################_COMPILATION_#################################
CC = gcc
FLAG =  #-Wall -Wextra -Werror -O3 # -g
LFT = ./libft/libft.a
SRCS = ./sources/main.c ./sources/get_info.c ./sources/tools.c ./sources/algo.c\
		./sources/bonus.c ./sources/count.c ./sources/place_piece.c \
		./sources/fill_up_form_left.c

OBJS = $(SRCS:.c=.o)

FMOD_DYLIB = ./fmod_lib/lib/libfmod.dylib

NAME = rabougue.filler
##################################_RELINK_MODIFY_.h#############################
RELINK_H = ./include/filler.h

all: $(NAME)

$(NAME): $(OBJS)
	@printf "♻️ $(GREY) Compiling ...\n$(GREY)"
	@make -s -C ./libft/
	@$(CC) $(FLAG) $(LFT) $(INCLUDE) $(OBJS) -o $(NAME)
	@printf "✅  Compilation done.\n"
	#@install_name_tool -change @rpath/libfmod.dylib $(FMOD_DYLIB) $(NAME)

%.o : %.c $(RELINK_H) ./Makefile
	@$(CC) -c $(FLAG) $< -o $@

clean:
	@printf "✅  $(GREY)all .o deleted\n"
	@rm -f $(OBJS)
	@make -s clean -C ./libft/

fclean:
	@printf "✅  $(GREY)libft.a, all .o and rabougue.filler deleted\n$(END)"
	@rm -f $(NAME) $(CHECKER) $(OBJS) $(OBJS_CHECKER)
	@make -s fclean -C ./libft/

re: fclean all
