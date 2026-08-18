# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/13 21:58:53 by htoe              #+#    #+#              #
#    Updated: 2026/02/14 20:50:45 by htoe             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#tips
#make CFLAGS+"-DBUFFER_SIZE=custom" for customize BUFFER_SIZE during gnl

#target
.DEFAULT_GOAL := all

#library_name
NAME = libft.a

#compilation and commands
CC = cc
CFLAGS = -Wall -Wextra -Werror
CINCLUDE = -Iinclude
AR = ar rcs
RM = rm -Rf

#Directories
SRCDIR = srcs
OBJDIR = objs
LIBC_DIR = libc
PRINTF_DIR = ft_printf
GNL_DIR = get_next_line
EXTRA_DIR = additional
BONUS_DIR = linkedlist

#source_files
SRCS = \
	${SRCDIR}/${LIBC_DIR}/ft_atoi.c \
	${SRCDIR}/${LIBC_DIR}/ft_bzero.c \
	${SRCDIR}/${LIBC_DIR}/ft_calloc.c \
	${SRCDIR}/${LIBC_DIR}/ft_isalnum.c \
	${SRCDIR}/${LIBC_DIR}/ft_isalpha.c \
	${SRCDIR}/${LIBC_DIR}/ft_isascii.c \
	${SRCDIR}/${LIBC_DIR}/ft_isdigit.c \
	${SRCDIR}/${LIBC_DIR}/ft_isprint.c \
	${SRCDIR}/${LIBC_DIR}/ft_memchr.c \
	${SRCDIR}/${LIBC_DIR}/ft_memcmp.c \
	${SRCDIR}/${LIBC_DIR}/ft_memcpy.c \
	${SRCDIR}/${LIBC_DIR}/ft_memmove.c \
	${SRCDIR}/${LIBC_DIR}/ft_memset.c \
	${SRCDIR}/${LIBC_DIR}/ft_strchr.c \
	${SRCDIR}/${LIBC_DIR}/ft_strdup.c \
	${SRCDIR}/${LIBC_DIR}/ft_strlcat.c \
	${SRCDIR}/${LIBC_DIR}/ft_strlcpy.c \
	${SRCDIR}/${LIBC_DIR}/ft_strlen.c \
	${SRCDIR}/${LIBC_DIR}/ft_strncmp.c \
	${SRCDIR}/${LIBC_DIR}/ft_strnstr.c \
	${SRCDIR}/${LIBC_DIR}/ft_strrchr.c \
	${SRCDIR}/${LIBC_DIR}/ft_tolower.c \
	${SRCDIR}/${LIBC_DIR}/ft_toupper.c \
	\
	${SRCDIR}/${EXTRA_DIR}/ft_itoa.c \
	${SRCDIR}/${EXTRA_DIR}/ft_putchar_fd.c \
	${SRCDIR}/${EXTRA_DIR}/ft_putendl_fd.c \
	${SRCDIR}/${EXTRA_DIR}/ft_putnbr_fd.c \
	${SRCDIR}/${EXTRA_DIR}/ft_putstr_fd.c \
	${SRCDIR}/${EXTRA_DIR}/ft_split.c \
	${SRCDIR}/${EXTRA_DIR}/ft_striteri.c \
	${SRCDIR}/${EXTRA_DIR}/ft_strjoin.c \
	${SRCDIR}/${EXTRA_DIR}/ft_strmapi.c \
	${SRCDIR}/${EXTRA_DIR}/ft_strtrim.c \
	${SRCDIR}/${EXTRA_DIR}/ft_substr.c \
	\
	${SRCDIR}/${PRINTF_DIR}/ft_printf.c \
	${SRCDIR}/${PRINTF_DIR}/ft_printf_utils.c \
	\
	${SRCDIR}/${GNL_DIR}/get_next_line.c \
	${SRCDIR}/${GNL_DIR}/get_next_line_utils.c

BSRCS = \
	${SRCDIR}/${BONUS_DIR}/ft_lstadd_back_bonus.c \
	${SRCDIR}/${BONUS_DIR}/ft_lstadd_front_bonus.c \
	${SRCDIR}/${BONUS_DIR}/ft_lstclear_bonus.c \
	${SRCDIR}/${BONUS_DIR}/ft_lstdelone_bonus.c \
	${SRCDIR}/${BONUS_DIR}/ft_lstiter_bonus.c \
	${SRCDIR}/${BONUS_DIR}/ft_lstlast_bonus.c \
	${SRCDIR}/${BONUS_DIR}/ft_lstmap_bonus.c \
	${SRCDIR}/${BONUS_DIR}/ft_lstnew_bonus.c \
	${SRCDIR}/${BONUS_DIR}/ft_lstsize_bonus.c


OBJS = ${SRCS:${SRCDIR}/%.c=${OBJDIR}/%.o}
BOBJS = ${BSRCS:${SRCDIR}/%.c=${OBJDIR}/%.o}

#pattern rules
${OBJDIR}/%.o: ${SRCDIR}/%.c Makefile
	@mkdir -p ${dir $@}
	@${CC} ${CFLAGS} ${CINCLUDE} -c $< -o $@

${NAME}: ${OBJS}
	@${AR} ${NAME} ${OBJS}

all: ${NAME}

#bonus rule
bonus: ${OBJS} ${BOBJS}
	@${AR} ${NAME} ${OBJS} ${BOBJS}

#cleaning up
clean:
	@${RM} ${OBJDIR}

fclean: clean
	@${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re bonus
