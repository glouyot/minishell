/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glouyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 11:17:07 by glouyot           #+#    #+#             */
/*   Updated: 2016/12/15 18:33:16 by glouyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char const *s, int fd)
{
	if (!s)
	{
		ft_error("No string in ft_putendl_fd input.");
		return ;
	}
	ft_putstr_fd((char *)s, fd);
	ft_putchar_fd('\n', fd);
}
