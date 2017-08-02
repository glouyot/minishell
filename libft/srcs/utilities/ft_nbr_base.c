/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glouyot <glouyot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 11:42:29 by glouyot           #+#    #+#             */
/*   Updated: 2017/05/30 15:21:06 by glouyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_nbr_base(int nb, char *base)
{
	if (!(ft_check_base(base)))
		return ;
	if (nb < 0)
	{
		ft_two_comp(nb);
	}
	else if (nb < (int)ft_strlen(base))
		ft_putchar(base[nb]);
	else
	{
		ft_putnbr_base((nb / (int)ft_strlen(base)), base);
		ft_putchar(base[nb % ft_strlen(base)]);
	}
}
