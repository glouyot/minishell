
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mkenv.c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glouyot <glouyot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 15:23:30 by glouyot           #+#    #+#             */
/*   Updated: 2017/10/10 15:23:30 by glouyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static t_env       *ft_initnewenv(char **newenv)
{
    t_env   *env;
    
    return (env);
}

t_env             *ft_initenv(char **newenv)
{
    static t_env    *env = NULL;
    static int      init = 0;

    if (init == 0 && newenv && (init = 1))
        env = ft_initnewenv(newenv);
    else
    {

    }
    return (env);
} 