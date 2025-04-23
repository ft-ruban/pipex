# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldevoude <ldevoude@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/05 15:21:37 by ldevoude          #+#    #+#              #
#    Updated: 2025/04/23 17:10:43 by ldevoude         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

#####################################################
##				 								   ##					
##                    VARIABLES                    ##
##												   ##
#####################################################

#####################################################
#				 PROGRAM + AUTHOR					#
#####################################################
AUTHOR 		   =   ldevoude
NAME		   =   pipex
#####################################################
#					COMPILING						#
#####################################################
CC             =   cc
#####################################################
#					FLAGS							#
#####################################################
CFLAGS         =   -Wall -Wextra -Werror

#####################################################
#					DIRECTORY						#
#####################################################
DIR_PIPEX  =   .
DIR_PIPEX_CHILD =  ./child
DIR_LIBFTX     =   ./libftx
OBJ_DIR        =   obj_pipex

#####################################################
#					ARCHIVES						#
#####################################################
AR 			=   ar rcs
LIBLIBFTX 	=   $(DIR_LIBFTX)/libftx.a

#####################################################
#					HEADER  						#
#####################################################
HEADER_PIPEX = $(DIR_PIPEX)/header/pipex.h
#####################################################
#					 MISC     						#
#####################################################
LIGHTPURPLE    =   \033[1;35m
GREEN		   =   \033[1;32m
RED            =   \033[1;31m

#####################################################
#					VARIABLES SOURCES				#
#####################################################
PIPEX_SRC    =   $(addsuffix .c, \
						main \
						child_pathed \
						child_in \
						child_out\
						child_utils \
						ft_pipex)

PIPEX_CHILD_SRC = $(addsuffix .c, \
						child_pathed\
						child_in \
						child_out\
						child_utils)

#####################################################
#					VARIABLES_OBJ				    #
#####################################################

PIPEX_OBJ = $(addprefix $(OBJ_DIR)/, $(PIPEX_SRC:.c=.o))
PIPEX_CHILD_OBJ = $(addprefix $(OBJ_DIR)/, $(PIPEX_CHILD_SRC:.c=.o))
DEPENDANCY_FILES =   $(PIPEX_OBJ:.o=.d) #to create dep

#####################################################
#					TARGETS						#
#####################################################

all             :    $(LIBLIBFTX) $(NAME)

clean           :	
								@rm -rf $(OBJ_DIR) $(PIPEX_OBJ)
								$(MAKE) -C $(DIR_LIBFTX) clean
								@rm -f $(DIR_GNL)*.d 
								@rm -f $(DIR_PRINTF)*.d
								@echo "$(GREEN)Cleaning of .o and .d files completed successfully! ／人◕ ‿‿ ◕人＼"
fclean          :    clean
								@rm -f $(NAME)
								$(MAKE) -C $(DIR_LIBFTX) fclean
								@echo "$(GREEN)Deleting $(NAME) completed successfully! ／人◕ ‿‿ ◕人＼ "
								@echo "$(RED)"
								@echo "┌──────────────────────────────────────────────────────────┐"
								@echo "│      Deletion finished successfully! ( ◔ ω ◔) ノシ         │"
								@echo "└──────────────────────────────────────────────────────────┘"
								
								@echo "                           ╱|、"
								@echo "                         (˚ˎ 。7"
								@echo "                          |、˜|"
								@echo "                         じしˍ,)ノ"
								@echo "$(RESET)"

	
debug           :   
					@echo "Current directory: $(shell pwd)"
					@ls -l $(DIR_PIPEX)
					@ls -l $(DIR_LIBFTX)
					@echo $(shell -e) "${LIGHTPURPLE}I never thought I'd see a Resonance Cascade, let alone create one!"

re               :	fclean all	

#####################################################
#					COMMANDS						#
#####################################################

$(NAME): $(OBJ_DIR) $(PIPEX_OBJ) $(PIPEX_CHILD_OBJ) $(HEADER_PIPEX) $(LIBLIBFTX)
		 $(CC) $(CFLAGS) -o $(NAME) $(PIPEX_OBJ) $(LIBLIBFTX)
		@echo "$(GREEN) $(NAME) is now ready to run ／人◕ ‿‿ ◕人＼ "

$(LIBLIBFTX): ./libftx/Makefile force
	$(MAKE)	-C $(DIR_LIBFTX)

force:

$(OBJ_DIR)/%.d: $(DIR_PIPEX)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I$(DIR_PIPEX) -MM -MP -MT '$(@:.d=.o) $@' -MF $@ $<

$(OBJ_DIR)/%.o	   : $(DIR_PIPEX)/%.c | $(OBJ_DIR)
					 $(CC) $(CFLAGS) -I$(DIR_PIPEX) -o $@ -c $<

$(OBJ_DIR)/%.o	   : $(DIR_PIPEX_CHILD)/%.c | $(OBJ_DIR)
					 $(CC) $(CFLAGS) -I$(DIR_PIPEX_CHILD) -o $@ -c $<					 

$(DIR_PIPEX)/%.o  :      $(DIR_PIPEX)/%.c $(HEADER_PIPEX)
											$(CC) $(CFLAGS) -c $< -o $@
									
$(OBJ_DIR)          :		
							mkdir -p $(OBJ_DIR)

-include $(DEPENDANCY_FILES)

.PHONY :   					all bonus clean fclean re
