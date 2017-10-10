/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glouyot <glouyot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/24 11:36:30 by glouyot           #+#    #+#             */
/*   Updated: 2017/10/06 16:25:04 by glouyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int			ft_inenv(char *key, t_env *env)
{
	int		i;

	i = -1;
	while (env->key[++i])
		if (ft_strcmp(key, env->key[i]) == 0)
			return (i);
	return (-1);
}

static int	ft_addenv(char *key, char *value, t_env *env)
{
	size_t	s;
	char	**tmp;

	s = ft_str_tab_len(env->key);
	tmp = ft_strarray_dup(env->key, sizeof(char *) * (s + 1));
	tmp[s] = ft_strdup(key);
	env->key = ft_strarray_dup(tmp, sizeof(char *) * (s + 1));
	ft_array_free(tmp);
	if (value)
	{
		tmp = ft_strarray_dup(env->value, sizeof(char *) * (s + 1));
		tmp[s] = (value != NULL) ? ft_strdup(value) : " ";
		env->value = ft_strarray_dup(tmp, sizeof(char *) * (s + 1));
		ft_array_free(tmp);
	}
	return (1);
}

int			ft_setenv(char **av)
{
	t_env	*env;
	int		index;
	int		len;

	env = ft_initenv(NULL);
	len = ft_str_tab_len(av);
	if (len <= 3 && len > 1)
	{
		index = ft_inenv(av[1], env);
		if (index >= 0)
			env->value[index] = (!(av[2]) ? " " : ft_strdup(av[2]));
		else
			ft_addenv(av[1], (av[2]) ? av[2] : " ", env);
		return (0);
	}
	return (1);
}
