# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rabougue <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/10 19:16:51 by rabougue          #+#    #+#              #
#    Updated: 2016/11/08 15:19:56 by rabougue         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


####################################FOR_FMOD####################################
#@install_name_tool -change @rpath/libfmod.dylib $(FMOD_DYLIB) $(NAME)
################################################################################

####################################_COLOR_#####################################
GREEN = \033[38;5;10m
GREY = \033[38;5;60m
RED = \033[38;5;9m
END = \033[0m
##################################_COMPILATION_#################################
NAME = rabougue.filler
CC = gcc
FLAG = -Wall -Wextra -Werror -O3
LFT = ./libft/libft.a
SRCS = ./sources/main.c ./sources/get_info.c ./sources/tools.c\
		./sources/bonus.c ./sources/count.c ./sources/place_piece.c \
		./sources/fill_up_form_left.c ./sources/fill_down_form_right.c\
		./sources/window.c ./sources/sdl_draw.c ./sources/algo.c \
		./sources/init.c ./sources/get_info_header.c ./sources/keyboard.c\

OBJS = $(SRCS:.c=.o)

####################################FOR_FMOD####################################
FMOD_DYLIB = ./fmod_lib/lib/libfmod.dylib
################################################################################

####################################FOR_SDL#####################################
LSDL = -L ./libsdl/ -lSDL2
FRAMEWORK = -framework OpenGL
SDL2DYLIB = ./libsdl/libSDL2-2.0.0.dylib
SDL2_image = ./libsdl/SDL2_image
SDL2_ttf = ./libsdl/SDL2_ttf.framework/Versions/A/SDL2_ttf
SDL2_mixer = ./libsdl/SDL2_mixer.framework/Versions/A/SDL2_mixer
SDL2_smpeg2 = ./libsdl/SDL2_mixer.framework/Versions/A/Frameworks/smpeg2.framework/smpeg2
################################################################################

###########################_RELINK_MODIFY_.h####################################
RELINK_H = ./include/filler.h
################################################################################

all: $(NAME)

$(NAME): $(OBJS)
	@make -s -C ./libft/
	@$(CC) $(FLAG) $(LSDL) $(LFT) $(SDL2_ttf) $(SDL2_mixer) $(INCLUDE) $(OBJS) -o $(NAME) $(FRAMEWORK)
	@printf "✅  Compilation done.\n"
	@install_name_tool -change /usr/local/lib/libSDL2-2.0.0.dylib $(SDL2DYLIB) $(NAME)
	@install_name_tool -change @rpath/SDL2_ttf.framework/Versions/A/SDL2_ttf $(SDL2_ttf) $(NAME)
	@install_name_tool -change @rpath/SDL2_mixer.framework/Versions/A/SDL2_mixer $(SDL2_mixer) $(NAME)
	@install_name_tool -change @rpath/SDL2.framework/Versions/A/SDL2 $(SDL2DYLIB) $(SDL2_ttf)
	@install_name_tool -change @executable_path/../Frameworks/SDL2.framework/Versions/A/SDL2 $(SDL2DYLIB) $(SDL2_smpeg2)

%.o : %.c $(RELINK_H) ./Makefile
	@printf "                                                               \r"
	@printf "✅  $(notdir $<)\r"
	@$(CC) -c $(FLAG) $< -o $@

clean:
	@printf "                                                               \r"
	@printf "✅  all .o deleted\n"
	@rm -f $(OBJS)
	@make -s clean -C ./libft/

fclean:
	@printf "                                                               \r"
	@printf "✅  libft.a, all .o and rabougue.filler deleted\n"
	@rm -f $(NAME) $(OBJS)
	@make -s fclean -C ./libft/

re: fclean all

norminette:
	@norminette ./libft/*.c ./libft/includes/*.h ./libft/ft_fprintf/sources/*.c\
	./libft/ft_fprintf/includes/*.h ./include/filler.h ./sources/*.c
