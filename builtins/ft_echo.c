/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glouyot <glouyot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/24 11:41:09 by glouyot           #+#    #+#             */
/*   Updated: 2017/10/11 13:16:40 by glouyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*ft_getvalue(char *cmd)
{
	char	*key;
	char	*ret;
	size_t	i;

	i = 1;
	key = (char *)ft_strnew(ft_strlen(cmd) - 1);
	while (i < ft_strlen(cmd))
	{
		key[i - 1] = cmd[i];
		i++;
	}
	ret = ft_getstrenv(key);
	ft_strdel(&key);
	return (ret);
}

int		ft_echo(char **av)
{
	int		i;
	char	*value;

	i = 0;
	while (av[++i])
	{
		if (i > 1)
			ft_putchar(' ');
		if (av[i][0] != '$')
			ft_putstr(av[i]);
		else
		{
			value = ft_getvalue(av[i]);
			if (value)
			{
				ft_putstr(value);
				free(value);
			}
		}
	}
	ft_putchar('\n');
	return (0);
}
