/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 03:41:51 by htoe              #+#    #+#             */
/*   Updated: 2026/08/19 05:19:03 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

volatile sig_atomic_t	g_signal_received;

static void	init_shell(char ***env_vars, char **env)
{
	*env_vars = copy_env(env);
	increment_shlvl(env_vars);
	setup_signals();
}

static void	shell_loop(char ***env, int *last_status)
{
	char	*line;

	while (1)
	{
		g_signal_received = 0;
		line = readline("minishell$ ");
		if (!line)
		{
			if (g_signal_received)
			{
				*last_status = 130;
				continue ;
			}
			if (isatty(STDIN_FILENO))
				ft_putendl_fd("exit", 1);
			break ;
		}
		if (g_signal_received)
			*last_status = 130;
		free(line);
	}
}

int	main(int ac, char **av, char **env)
{
	char	**env_vars;
	int		last_status;

	(void)ac;
	(void)av;
	init_shell(&env_vars, env);
	last_status = 0;
	g_signal_received = 0;
	shell_loop(&env_vars, &last_status);
	rl_clear_history();
	free_split(env_vars);
	return (0);
}
