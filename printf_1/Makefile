# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/16 04:58:35 by wwallas-          #+#    #+#              #
#    Updated: 2022/06/24 22:30:14 by wwallas-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT_PATH			=	./libft
LIBFT				=	$(LIBFT_PATH)/libft.a

SOURCES 			=	conversions.c ft_printf.c print_hex.c print_int.c
SOURCES 			+=	print_pointer.c print_unsigned.c put_char.c put_str.c
SOURCES				+=	print_padding.c verific_bonus.c padding.c rest_flgs.c
SOURCES				+=	precision.c verific_precision.c

OBJS_DIR			=	objetos

OBJS				=	$(SOURCES:%.c=$(OBJS_DIR)/%.o)

NAME				=	libftprintf.a

CC 					=	cc
CFLAGS 				=	-g3 -Wextra -Wall -Werror

AR 					=	ar rcs
RM					=	rm -rf

$(OBJS_DIR)/%.o:	%.c 
							$(CC) $(CFLAGS) -c $< -o $@ -I.

all:				$(NAME)

$(NAME):			$(LIBFT) $(OBJS_DIR) $(OBJS) $(H_SORCS)
							cp	$(LIBFT) $@
							$(AR) $@ $(OBJS) $(H_SORCS)

$(LIBFT):
							$(MAKE) -C $(LIBFT_PATH) bonus

$(OBJS_DIR):
							mkdir -p $@
							
bonus:				all

clean:
							$(MAKE) -C $(LIBFT_PATH) clean
							$(RM) $(OBJS_DIR)

fclean:				clean
							$(MAKE) -C $(LIBFT_PATH) fclean
							$(RM) $(NAME)

re:					fclean all

.PHONY:				all clean fclean re name libft bonus