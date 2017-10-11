/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glouyot <glouyot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/24 11:36:06 by glouyot           #+#    #+#             */
/*   Updated: 2017/10/11 13:13:26 by glouyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static char		**ft_newenv(char **newenv, int index, t_env *env)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (env->key[i])
	{
		if (i != index)
		{
			newenv[j] = ft_strdup(env->key[i]);
			newenv[j] = ft_strjoini(newenv[j], "=", 1);
			newenv[j] = ft_strjoini(newenv[j], env->value[i], 1);
			j++;
		}
		i++;
	}
	return (newenv);
}

int				ft_unsetenv(char **av)
{
	t_env	*env;
	int		size;
	int		index;
	char	**newenv;

	env = ft_initenv(NULL);
	size = ft_str_tab_len(env->key) - 1;
	if (av[1])
	{
		index = ft_inenv(av[1], env);
		if (!(newenv = (char **)ft_memalloc(sizeof(char *) * (size + 1))))
			return (1);
		if (index)
			newenv = ft_newenv(newenv, index, env);
		ft_initenv(newenv);
	}
	return (0);
}
