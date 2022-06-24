# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/16 04:58:35 by wwallas-          #+#    #+#              #
#    Updated: 2022/06/24 18:49:03 by wwallas-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT_PATH			=	./libft
LIBFT				=	$(LIBFT_PATH)/libft.a

SOURCES 			=	ft_printf.c print_hex.c print_int.c print_pointer.c
SOURCES 			+=	print_unsigned.c put_char.c put_str.c conversions.c

OBJS_DIR			=	objs
OBJS				=	$(patsubst %.c,objs/%.o,$(SOURCES)) 

SOURCES_BONUS		=	ft_printf_bonus.c      \
						print_hex_bonus.c      \
						print_int_bonus.c      \
						print_pointer_bonus.c  \
						print_unsigned_bonus.c \
						put_char_bonus.c       \
						put_str_bonus.c        \
						padding.c              \
						precision.c            \
						rest_flags.c           \
						verific_precision.c    \
						print_padding.c        \
						verific_bonus.c

OBJS_BONUS			=	$(patsubst %.c,objs/%.o, $(SOURCES_BONUS)) 

NAME				=	libftprintf.a

CC 					=	cc
CFLAGS 				=	-g3 -Wextra -Wall -Werror

AR 					=	ar rcs
RM					=	rm -rf

VPATH				=	. bonus 

$(OBJS_DIR)/%.o:	%.c $(H_SORCS)
						$(CC) $(CFLAGS) -c $< -o $@ -I.

all:				$(NAME)

$(NAME):			$(LIBFT) $(OBJS_DIR) $(OBJS)
							cp	$(LIBFT) $@
							$(AR) $@ $(OBJS)

$(LIBFT):
							$(MAKE) -C $(LIBFT_PATH) bonus

$(OBJS_DIR):
							mkdir -p $@
							
bonus:				all $(OBJS_BONUS)
							$(AR) $(NAME) $(OBJS_BONUS);

clean:
							$(MAKE) -C $(LIBFT_PATH) clean
							$(RM) $(OBJS_DIR)

fclean:				clean
							$(MAKE) -C $(LIBFT_PATH) fclean
							$(RM) $(NAME)

re:					fclean all

.PHONY:				all clean fclean re name libft bonus