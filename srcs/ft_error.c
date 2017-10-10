/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glouyot <glouyot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 10:18:11 by glouyot           #+#    #+#             */
/*   Updated: 2017/10/03 10:19:21 by glouyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void		ft_errornoenv(char *env)
{
	ft_putstr_fd(env, 2);
	ft_putendl_fd(": Undefined variable.", 2);
}
