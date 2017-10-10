/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glouyot <glouyot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 15:58:28 by glouyot           #+#    #+#             */
/*   Updated: 2017/10/09 13:25:35 by glouyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_delenv(void)
{
	t_env	*env;

	env = ft_initenv(NULL);
	ft_array_free(env->key);
	ft_array_free(env->value);
	free(env);
}
