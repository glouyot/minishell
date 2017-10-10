/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glouyot <glouyot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/24 11:36:55 by glouyot           #+#    #+#             */
/*   Updated: 2017/10/09 13:13:47 by glouyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int	ft_gotooldpwd(t_env *env)
{
	char	*oldpwd;
	char	*pwd;
	int		ret;

	oldpwd = (ft_getstrenv("OLDPWD")) ? ft_getstrenv("OLDPWD") : NULL;
	pwd = ft_strnew(4096);
	pwd = (ft_getstrenv("PWD")) ? ft_getstrenv("PWD") : getcwd(pwd, 4096);
	if (ft_inenv("OLDPWD", env))
	{
		if (!chdir(oldpwd))
		{
			ft_setenv(ft_strsplit(ft_strjoini("old=PWD=", oldpwd, 2), '='));
			ft_setenv(ft_strsplit(ft_strjoini("old=OLDPWD=", pwd, 2), '='));
		}
		ret = 0;
	}
	else
	{
		ft_setenv(ft_strsplit(ft_strjoini("old=OLDPWD=", pwd, 2), '='));
		ret = 1;
	}
	return (ret);
}

static char	*ft_cleantild(t_env *env)
{
	char	*ret;

	if (ft_inenv("HOME", env) != -1)
		ret = ft_strjoini(ft_strnew(1), ft_getstrenv("HOME"), 3);
	else
		ret = ft_strjoini(ft_strnew(1), "/", 1);
	return (ret);
}

static void	ft_newpwd(void)
{
	ft_setenv(ft_strsplit(ft_strjoini("w=OLDPWD=",
			ft_getstrenv("PWD"), 2), '='));
	ft_setenv(ft_strsplit(ft_strjoini("w=PWD=",
			getcwd(ft_strnew(4096), 4096), 2), '='));
}

int			ft_cd(char **av)
{
	int		i;
	t_env	*env;

	env = ft_initenv(NULL);
	i = 0;
	if (ft_inenv("PWD", env) < 0)
		ft_setenv(ft_strsplit(ft_strjoini("w=PWD=",
				getcwd(ft_strnew(4096), 4096), 2), '='));
	if (av[1] && (ft_strequ(av[1], "~") == 1))
	{
		free(av[1]);
		av[1] = ft_cleantild(env);
		if (!chdir(av[1]))
			ft_newpwd();
	}
	else if (av[1] && ft_strequ(av[1], "-") == 1)
		return (ft_gotooldpwd(env));
	else if (!chdir(av[1]))
		ft_newpwd();
	return (0);
}
