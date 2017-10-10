/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_help.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glouyot <glouyot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/24 11:34:15 by glouyot           #+#    #+#             */
/*   Updated: 2017/09/24 17:07:23 by glouyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int		ft_help(char **av)
{
	int		i;
	t_blts	*builtins;

	ft_putendl("Glouyot's minishell");
	ft_putendl("The following are built in:");
	i = 0;
	builtins = blts();
	while (i < NBR_BUILTINS)
		ft_putendl(builtins[i++].name);
	return (av ? 1 : 1);
}
