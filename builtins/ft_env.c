/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glouyot <glouyot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/24 11:35:31 by glouyot           #+#    #+#             */
/*   Updated: 2017/10/11 17:15:46 by glouyot          ###   ########.fr       */
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
		ret[i] = ft_strjoini(ret[i], env->value[i], 1);
		i++;
	}
	free(env);
	return (ret);
}

void		ft_cleanenv(t_env *env)
{
	if (env)
	{
		ft_array_free(env->key);
		ft_array_free(env->value);
		free(env);
	}
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
