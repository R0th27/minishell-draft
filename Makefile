# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/03 14:28:26 by htoe              #+#    #+#              #
#    Updated: 2026/08/19 06:34:48 by htoe             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#target
.DEFAULT_GOAL := all

#Compilation & Commands
NAME = minishell
CC = cc
CFLAGS = -Wall -Wextra -Werror
CINCLUDES = -Iinclude -Ilibft/include
LIBFLAGS = -Llibft -lft -lreadline
RM = rm -Rf

#Directories
OBJ_DIR = obj
SRC_DIR = src

#Sources
SRC_PARSING = lexer.c lexer_utils.c parser.c parser_utils.c parser_redir.c \
              token_utils.c expand_utils.c expand_vars.c expand_helpers.c \
              wildcards.c wildcard_helpers.c wildcards_exec.c
SRC_EXEC    = executor.c executor_main.c builtin_executor.c exec_utils.c \
              exec_loop.c redirection.c redirection_utils.c path_utils.c
SRC_BUILTIN = builtins.c builtins_utils.c env_builtins.c
SRC_UTILS   = env_utils.c
SRC_ROOT    = main.c signals.c

SRCS = $(addprefix $(SRC_DIR)/parsing/, $(SRC_PARSING)) \
       $(addprefix $(SRC_DIR)/execution/, $(SRC_EXEC)) \
       $(addprefix $(SRC_DIR)/builtins/, $(SRC_BUILTIN)) \
       $(addprefix $(SRC_DIR)/utils/, $(SRC_UTILS)) \
       $(addprefix $(SRC_DIR)/, $(SRC_ROOT))

OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
LIBS = libft/libft.a

#Pattern Rules
${OBJ_DIR}/%.o: ${SRC_DIR}/%.c Makefile
	@mkdir -p ${dir $@}
	@${CC} ${CFLAGS} ${CINCLUDES} -c $< -o $@

${LIBS}:
	@echo "COMPILING LIBFT"
	@make -s -C libft

${NAME}: Makefile ${OBJS} ${LIBS}
	@echo "COMPILING MINISHELL"
	@echo "LINKING MINISHELL"
	@${CC} ${OBJS} ${LIBFLAGS} -o ${NAME}
	@echo "FINISHED"
	
all: ${NAME}

clean:
	@echo "CLEANING"
	@${RM} ${OBJ_DIR}
	@make clean -s -C libft

fclean: clean
	@${RM} ${NAME}
	@make fclean -s -C libft

re: fclean all

.PHONY: all clean fclean re
