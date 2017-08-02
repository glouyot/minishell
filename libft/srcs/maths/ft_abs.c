/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glouyot <glouyot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 14:15:43 by glouyot           #+#    #+#             */
/*   Updated: 2017/05/30 15:15:11 by glouyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_maths.h"

inline int		ft_abs(int nb)
{
	return (nb < 0 ? -nb : nb);
}

inline t_ll		ft_abs(t_ll nb)
{
	return (nb < 0 ? -nb : nb);
}

inline t_ull	ft_abs(t_ull nb)
{
	return (nb < 0 ? -nb : nb);
}
