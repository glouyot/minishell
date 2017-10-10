/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glouyot <glouyot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 15:49:25 by glouyot           #+#    #+#             */
/*   Updated: 2017/10/10 12:18:07 by glouyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static char		*ft_gencmd(char *cmd)
{
	char	*ret;
	char	**path;
	int		i;

	path = ft_strsplit(ft_getstrenv("PATH"), ':');
	i = 0;
	if (path)
	{
		while (path[i])
		{
			ret = ft_strdup(path[i]);
			ret = ft_strjoini(ret, "/", 1);
			ret = ft_strjoini(ret, cmd, 1);
			if (access(ret, F_OK) == 0)
			{
				ft_array_free(path);
				return (ret);
			}
			i++;
		}
	}
	if (access(cmd, F_OK) == 0)
	{
		return (cmd);
	}
	return (NULL);
}

static char		**m_checkpath(char **env)
{
	t_env	*tenv;
	char	*line;
	char	**ret;
	int		fd;
	char	*add;

	tenv = ft_initenv(NULL);
	if (ft_inenv("PATH", tenv) == -1)
	{
		add = ft_strjoin("PATH=", "");
		ret = env;
		fd = open("/etc/paths", O_RDONLY);
		while (get_next_line(fd, &line) == 0)
		{
			add = ft_strjoini(add, ft_strjoin(ft_strdup(line), ":"), 1);
			free(line);
		}
		ft_putendl(add);
		ft_strarrayadd(env, add);
		for(int i = 0; env[i];i++)
		ft_putendl(env[i]);
		ft_strdel(&add);
	}
	return (env);
}

static int		m_execute(char **cmd)
{
	pid_t	pid;
	pid_t	wpid;
	int		state;
	char	**env;
	int		ret;

	env = (PATH == 0) ? m_checkpath(ft_envchar()) : ft_envchar();
	ret = 0;
	pid = fork();
	if (pid == 0)
	{
		if (execve(ft_gencmd(cmd[0]), cmd, env) == -1)
			ft_putendl_fd(ft_strjoin("Minishell: command not found: ", cmd[0]), 2);
		exit(1);
	}
	else if (pid < 0)
	{
		ft_putendl_fd("fork pas content", 2);
	}
	else
	{
		wpid = waitpid(pid, &state, WUNTRACED);
		while (!WIFEXITED(state) && !WIFSIGNALED(state))
			wpid = waitpid(pid, &state, WUNTRACED);
	}
	//ft_array_free(env);
	return (ret);
}

t_blts			*blts(void)
{
	static t_blts	builtins[NBR_BUILTINS] = {
		{"cd", ft_cd},
		{"echo", ft_echo},
		{"setenv", ft_setenv},
		{"unsetenv", ft_unsetenv},
		{"env", ft_env},
		{"exit", ft_exit},
		{"getenv", ft_getenv},
		{"help", ft_help}
	};

	return (builtins);
}

int				m_exec(char **cmd)
{
	int		i;
	t_blts	*builtins;

	if (!cmd[0])
		return (1);
	i = 0;
	builtins = blts();
	while (i < NBR_BUILTINS)
	{
		if (ft_strcmp(cmd[0], builtins[i].name) == 0)
			return ((*builtins[i].f)(cmd));
		i++;
	}
	return (m_execute(cmd));
}
