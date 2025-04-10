# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldevoude <ldevoude@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/05 15:21:37 by ldevoude          #+#    #+#              #
#    Updated: 2025/04/10 14:29:10 by ldevoude         ###   ########lyon.fr    #
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
CFLAGS         =   -Wall -Wextra -Werror -g

#####################################################
#					DIRECTORY						#
#####################################################
DIR_PIPEX  =   .
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
						check_cmd \
						check_file \
						check_utils \
						check \
						utils)

#####################################################
#					VARIABLES_OBJ				    #
#####################################################

PIPEX_OBJ = $(addprefix $(OBJ_DIR)/, $(PIPEX_SRC:.c=.o))

#DELETE_MOI_OBJ = $(addprefix $(OBJ_DIR)/, $(DELETE_MOI_SRC:.c=.o))
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
					@echo "Checking push_swap files\:"
					@ls -l $(DIR_PIPEX)
					@echo "Checking libftx files\:"
					@ls -l $(DIR_LIBFTX)
					@echo $(shell -e) "${LIGHTPURPLE}I never thought I'd see a Resonance Cascade, let alone create one!"

re               :	fclean all	

#####################################################
#					COMMANDS						#
#####################################################

$(LIBLIBFTX):
	$(MAKE) -C $(DIR_LIBFTX)

$(NAME): $(OBJ_DIR) $(PIPEX_OBJ) $(HEADER_PIPEX) $(LIBLIBFTX)
		 $(CC) $(CFLAGS) -o $(NAME) $(PIPEX_OBJ) $(LIBLIBFTX)
		@echo "$(GREEN) $(NAME) is now ready to run ／人◕ ‿‿ ◕人＼ "

$(OBJ_DIR)/%.o	   : $(DIR_PIPEX)/%.c | $(OBJ_DIR)
					 $(CC) $(CFLAGS) -I$(DIR_PIPEX) -o $@ -c $<

$(DIR_PIPEX)/%.o  :      $(DIR_PIPEX)/%.c $(HEADER_PIPEX)
											$(CC) $(CFLAGS) -c $< -o $@
									
$(OBJ_DIR)          :		
							mkdir -p $(OBJ_DIR)

-include $(DEPENDANCY_FILES)

.PHONY :   					all bonus clean fclean re
