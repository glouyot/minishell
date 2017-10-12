/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glouyot <glouyot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 15:46:14 by glouyot           #+#    #+#             */
/*   Updated: 2017/10/12 11:01:37 by glouyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char		*ft_getstrenv(char *cmd)
{
	t_env	*env;
	int		i;
	char	*ret;

	env = ft_initenv(NULL);
	i = 0;
	ret = NULL;
	if (cmd)
	{
		while (env->key[i])
		{
			if (ft_strequ(env->key[i], cmd))
				ret = (env->value[i]) ? ft_strdup(env->value[i]) : NULL;
			i++;
		}
	}
	return (ret);
}

int			ft_getenv(char **av)
{
	t_env	*env;
	int		i;

	if (av[1] && ft_strcmp("-i", av[1]) == 0)
	{
		ft_putendl("Environ tout vide");
	}
	else
	{
		env = ft_initenv(NULL);
		i = 0;
		while (env->key[i])
		{
			if (ft_strequ(env->key[i], av[1]))
			{
				ft_putstr(env->key[i]);
				ft_putchar('=');
				if (env->value[i])
					ft_putendl(env->value[i]);
			}
			i++;
		}
	}
	return (av ? 1 : 1);
}
