# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgerard <mgerard@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/20 09:24:55 by mgerard           #+#    #+#              #
#    Updated: 2026/05/20 19:08:21 by nlovius          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC = all_in_history.c\
      chunk_utils.c\
      chunk_sort.c\
      disorder.c\
      do_print.c\
      flag_detect.c\
      do_sort.c\
      ft_push.c\
      ft_swap.c\
      is_double_num.c\
      malloc_stacks.c\
      parse_args.c\
      rotate.c\
      simple_sort.c\
      radix.c\
      main.c

LIBFT_SRC = libft/ft_isalpha.c libft/ft_isdigit.c libft/ft_isalnum.c libft/ft_isascii.c libft/ft_isprint.c \
       libft/ft_strlen.c libft/ft_memset.c libft/ft_bzero.c libft/ft_memcpy.c libft/ft_memmove.c \
       libft/ft_strlcpy.c libft/ft_strlcat.c libft/ft_toupper.c libft/ft_tolower.c libft/ft_strchr.c \
       libft/ft_strrchr.c libft/ft_strncmp.c libft/ft_memchr.c libft/ft_memcmp.c libft/ft_strnstr.c \
       libft/ft_atoi.c libft/ft_calloc.c libft/ft_strdup.c \
       libft/ft_substr.c libft/ft_strjoin.c libft/ft_strtrim.c libft/ft_split.c libft/ft_itoa.c \
       libft/ft_strmapi.c libft/ft_striteri.c libft/ft_putchar_fd.c libft/ft_putstr_fd.c \
       libft/ft_putendl_fd.c libft/ft_putnbr_fd.c\
       libft/ft_lstnew.c libft/ft_lstadd_front.c libft/ft_lstsize.c libft/ft_lstlast.c \
       libft/ft_lstadd_back.c libft/ft_lstdelone.c libft/ft_lstclear.c libft/ft_lstiter.c \
       libft/ft_lstmap.c libft/print_f.c libft/ft_putdecimal.c libft/ft_puttext.c \
       libft/ft_puthexa.c

OBJ = $(SRC:.c=.o)

LIBFT_OBJ = $(LIBFT_SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT_OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT_OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT_DIR)/%.o: $(LIBFT_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(LIBFT_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean
