/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 04:34:32 by htoe              #+#    #+#             */
/*   Updated: 2026/08/19 04:47:01 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	increment_shlvl(char ***env)
{
	char	*shlvl;
	int		val;
	char	*new_val;

	shlvl = get_env_value(*env, "SHLVL");
	if (!shlvl)
		set_env(env, "SHLVL", "1");
}
