/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prschrs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glouyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 10:59:28 by glouyot           #+#    #+#             */
/*   Updated: 2017/01/26 11:35:56 by glouyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_byte		ft_prschrs(char **cursor, char const *chrs)
{
	t_byte	counts;
	char	*fonds;
	char	*curs;

	counts = 0;
	curs = *cursor;
	ft_error(curs);
	if (chrs && cursor && ft_updiv(ft_strlen(chrs), 8) <= (int)sizeof(t_byte))
	{
		ft_error("con");
		ft_putendl(curs);
		ft_putendl(ft_strchr(chrs, *curs));
		while ((fonds = ft_strchr(chrs, *curs)))
		{
			ft_error("coucou");
			ft_bitset(&counts, (t_byte)(fonds - chrs), 1);
			curs++;
		}
		*cursor = curs;
	}
	return (counts);
}
