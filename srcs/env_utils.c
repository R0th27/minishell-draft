/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 04:27:14 by htoe              #+#    #+#             */
/*   Updated: 2026/08/19 05:04:36 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**copy_env(char **env)
{
	char	**new_env;
	int		i;
	int		count;

	count = 0;
	while (env[count])
		count++;
	new_env = (char **)malloc(sizeof(char *) * (count + 1));
	if (!new_env)
		return (NULL);
	i = -1;
	while (++i < count)
		new_env[i] = ft_strdup(env[i]);
	new_env[i] = NULL;
	return (new_env);
}

char	*get_env_value(char **env, char *key)
{
	int	i;
	int	key_len;

	i = 0;
	key_len = ft_strlen(key);
	while (env[i])
	{
		if (!ft_strncmp(env[i], key, key_len) && env[i][key_len] == '=')
			return (env[i] + key_len + 1);
		i++;
	}
	return (NULL);
}

static int	update_env(char **env, char *key, char *val, int l)
{
	int	i;

	i = -1;
	while (env[++i])
	{
		if (!ft_strncmp(env[i], key, l) && env[i][l] == '=')
		{
			free(env[i]);
			env[i] = val;
			return (1);
		}
	}
	return (0);
}

void	set_env(char ***env, char *key, char *value)
{
	char	**new;
	char	*s;
	char	*t;
	int		i;

	t = ft_strjoin(key, "=");
	s = ft_strjoin(t, value);
	free(t);
	if (update_env(*env, key, s, ft_strlen(key)))
		return ;
	i = 0;
	while ((*env)[i])
		i++;
	new = (char **)malloc(sizeof(char *) * (i + 2));
	ft_memcpy(new, *env, sizeof(char *) * i);
	new[i] = s;
	new[i + 1] = NULL;
	free(*env);
	*env = new;
}
