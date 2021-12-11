# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/08 15:05:09 by hthomas           #+#    #+#              #
#    Updated: 2021/12/11 20:03:31 by hthomas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	hotrace

CC			=	cc
CFLAGS		=	-Ofast #-Wall -Werror -Wextra
LDFLAGS		=	#-g3 -fsanitize=address #-fsanitize=leak

OBJS		=	$(SRCS:.c=.o)
INCL		=	includes/
HEADER		=	$(INCL)$(NAME).h					\
				$(INCL)Linked-list.h

SRCS		=	srcs/main.c							\
				srcs/utils.c						\
				srcs/utils2.c

# linked_list
SRCS		+=	srcs/linked_list/ft_lstnew.c		\
				srcs/linked_list/ft_lstadd_front.c	\
				srcs/linked_list/ft_lstsize.c		\
				srcs/linked_list/ft_lstremove_one.c	\
				srcs/linked_list/ft_lstlast.c		\
				srcs/linked_list/ft_lstadd_back.c	\
				srcs/linked_list/ft_lstdelone.c		\
				srcs/linked_list/ft_lstclear.c		\
				srcs/linked_list/ft_lstiter.c		\
				srcs/linked_list/ft_lstmap.c		\
########################### EXEC
all:		$(NAME)

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $(OBJS)

########################### OBJECTS
%.o:		%.c $(HEADER)
	$(CC) -c $(CFLAGS) $(LDFLAGS) -I $(INCL) -o $@ $<

########################### CLEAN
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(OBJS)
	rm -f $(NAME) a.out

re:			fclean all
.PHONY:		re clean fclean test test_hotrace test_leaks
# .SILENT:

########################### RUN

run:		$(NAME)
	./$<

run_time:		$(NAME)
	time ./$<

run_leaks:	$(NAME)
	leaks -atExit -- ./$<
