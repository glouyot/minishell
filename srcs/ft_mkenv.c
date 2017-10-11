/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mkenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glouyot <glouyot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 09:32:54 by glouyot           #+#    #+#             */
/*   Updated: 2017/10/11 10:29:47 by glouyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static void	ft_inittenv(char **env, size_t index, t_env **tenv)
{
	char	**split;

	split = ft_strsplit(env[index], '=');
	(*tenv)->key[index] = ft_strdup(split[0]);
	(*tenv)->value[index] = (split[1]) ? ft_strdup(split[1]) : " ";
	ft_array_free(split);
}

static t_env	*ft_initnewenv(char **newenv)
{
	t_env   *env;
	size_t  s;
	size_t	i;
	
	if (!(env = (t_env *)ft_memalloc(sizeof(t_env))))
		return (NULL);
	s = ft_str_tab_len(newenv);
	env->key = (char **)ft_memalloc(sizeof(char *) * (s + 1));
	env->value = (char **)ft_memalloc(sizeof(char *) * (s + 1));
	if ((i = 0) && (!env->key || !env->value))
		return (NULL);
	while (i < s)
	{
		ft_inittenv(newenv, i, &env);
		i++;
	}
	return (env);
}

t_env			*ft_initenv(char **newenv)
{
	static t_env	*env = NULL;
	static int		init = 0;

	if (init == 0 && newenv && (init = 1))
		env = ft_initnewenv(newenv);
	else if (init == 1 && newenv)
	{
		ft_cleanenv(env);
		env = ft_initnewenv(newenv);
		ft_array_free(newenv);
	}
	return (env);
} 