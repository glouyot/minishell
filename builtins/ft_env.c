/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glouyot <glouyot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/24 11:35:31 by glouyot           #+#    #+#             */
/*   Updated: 2017/10/10 14:39:04 by glouyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char		**ft_envchar(void)
{
	t_env	*env;
	char	**ret;
	int		i;

	env = ft_initenv(NULL);
	if (!(ret = (char **)ft_memalloc(sizeof(char *) *
			ft_str_tab_len(env->key))))
		return (NULL);
	i = 0;
	while (env->key[i])
	{
		ret[i] = ft_strjoin(env->key[i], "=");
		ret[i] = ft_strjoin(ret[i], env->value[i]);
		i++;
	}
	ret[i] = NULL;
	return (ret);
}

void		ft_cleanenv(t_env **env)
{
	if (*env && env)
	{
		ft_array_free((*env)->key);
		ft_array_free((*env)->value);
		free(*env);
	}
}

static void	ft_inittenv(char **env, size_t index, t_env **tenv)
{
	char	**split;

	split = ft_strsplit(env[index], '=');
	(*tenv)->key[index] = ft_strdup(split[0]);
	(*tenv)->value[index] = (split[1]) ? ft_strdup(split[1]) : " ";
	ft_array_free(split);
}

t_env		*ft_initenv(char **env)
{
	static t_env	*tenv = NULL;
	size_t			s;
	size_t			i;

	if (env && (s = ft_str_tab_len(env)))
	{
		if (tenv)
			ft_cleanenv(&tenv);
		if (!(tenv = (t_env *)ft_memalloc(sizeof(t_env))))
			return (NULL);
		tenv->key = (char **)ft_memalloc(sizeof(char *) * (s + 1));
		tenv->value = (char **)ft_memalloc(sizeof(char *) * (s + 1));
		i = 0;
		if (!tenv->key || !tenv->value)
			return (NULL);
		while (i < s)
		{
			ft_inittenv(env, i, &tenv);
			i++;
		}
		tenv->key[i] = NULL;
		tenv->value[i] = NULL;
	}
	return (tenv);
}

int			ft_env(char **av)
{
	t_env	*env;
	int		i;

	env = ft_initenv(NULL);
	if (av[1] && ft_strcmp("-i", av[1]) == 0)
	{
		ft_putendl("Environ tout vide");
	}
	else
	{
		i = 0;
		while (env->key[i])
		{
			ft_putstr(env->key[i]);
			ft_putchar('=');
			if (env->value[i])
				ft_putendl(env->value[i]);
			else
				ft_putchar('\n');
			i++;
		}
	}
	return (av ? 1 : 1);
}
