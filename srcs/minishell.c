/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glouyot <glouyot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/08 10:41:34 by glouyot           #+#    #+#             */
/*   Updated: 2017/10/11 15:03:44 by glouyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int		main(int ac, char **av, char **env)
{
	t_env	*tenv;

	tenv = ft_initenv(env);
	signal(SIGINT, signals);
	if (ac && av)
		;
	m_loop();
	//ft_cleanenv(tenv);
	return (EXIT_SUCCESS);
}
