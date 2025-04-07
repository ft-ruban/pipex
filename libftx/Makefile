#####################################################
#					PROGRAM							#
#####################################################
NAME = libftx.a

#####################################################
#					COMPILING						#
#####################################################
CC = cc
#####################################################
#					DIRECTORY						#
#####################################################
DIR_LIBFTX  = .
DGNL        = ./get_next_line
DPRINTF     = ./printf
#####################################################
#					FLAGS							#
#####################################################
CFLAGS = -Wall -Wextra -Werror
#####################################################
#					FILES							#
#####################################################
CFILES = 	ft_argv_to_int_array.c \
			ft_atoi.c\
			ft_atop.c\
			ft_bzero.c \
			ft_calloc.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isintsized.c \
			ft_isprint.c \
			ft_itoa.c \
			ft_itoa_hexx.c\
			ft_memchr.c \
			ft_memcmp.c	\
			ft_memcpy.c	\
			ft_memmove.c \
			ft_memset.c \
			ft_putchar_fd.c \
			ft_putnbr_fd.c \
			ft_putendl_fd.c \
			ft_putstr_fd.c \
			ft_split.c \
			ft_strchr.c \
			ft_strcmp.c \
			ft_strdup.c \
			ft_striteri.c \
			ft_strjoin.c \
			ft_strlcat.c \
			ft_strlcpy.c \
			ft_strlen.c \
			ft_strmapi.c \
			ft_strncmp.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_strtoupper.c \
			ft_strtrim.c \
			ft_substr.c \
			ft_tolower.c \
			ft_toupper.c \
			ft_utoa.c \
			printf/ft_printf.c \
			printf/ft_printf_cases.c\
			printf/ft_printfd.c \
			printf/ft_printfd_cases.c\
			get_next_line/get_next_line.c\

#SRC?
OBJ = $(CFILES:.c=.o)
HEADERS		=	$(DGNL)/get_next_line.h\
				$(DPRINTF)/ft_printf.h

#####################################################
#					ARCHIVES						#
#####################################################

AR				=	ar
AFLAG			=	rcs
LIBPRINTF		=	$(DPRINTF)/printf.a

#####################################################
#					HEADER  						#
#####################################################
HEADER_LIBFTX = $(DIR_LIBFTX)/libft.h

#####################################################
#                   TARGETS                         #
#####################################################
all: $(NAME)

$(NAME): $(OBJ) $(HEADER_LIBFTX)
	$(AR) $(AFLAG) $(NAME) $(OBJ)

$(LIBPRINTF):
	$(MAKE) -C $(DPRINTF)

#rules to create objects files
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean objects and gen files
clean:
	@rm -f $(OBJ)
	@rm -f $(DIR_LIBFTX)/printf/*.o
	@rm -f $(DIR_LIBFTX)/get_next_line/*.o
	@echo "Cleaning completed!"

# Fclean  (complete clean)
fclean: clean
	rm -f $(NAME)

#rebuild
re: fclean all

.PHONY: all clean fclean re
