
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signals.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glouyot <glouyot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 14:07:27 by glouyot           #+#    #+#             */
/*   Updated: 2017/10/11 14:07:27 by glouyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "../include/minishell.h"

void	signals(int signum)
{
	if (signum == 2)
	{
		ft_putendl("");
		ft_prompt();
	}
	else
	{
		ft_putendl("coucou");
		ft_putendl(ft_itoa(signum));
	}
}
