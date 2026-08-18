/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 03:41:04 by htoe              #+#    #+#             */
/*   Updated: 2026/08/19 05:14:43 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <signal.h>
# include <errno.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "libft.h"

//# define PROMPT "minishell$ "

extern volatile sig_atomic_t	g_signal_received;

char	**copy_env(char **env);
void	free_split(char **split);

void	increment_shlvl(char ***env);
char	*get_env_value(char **env, char *key);
void	set_env(char ***env, char *key, char *value);

void	setup_signals(void);

#endif
