/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarray_dup.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glouyot <glouyot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 14:29:23 by glouyot           #+#    #+#             */
/*   Updated: 2017/09/27 13:58:55 by glouyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strarray_dup(char **src, size_t s)
{
	char	**ret;
	int		i;

	if (!(ret = (char **)ft_memalloc(sizeof(char *) * s)))
		return (NULL);
	i = 0;
	while (src[i])
	{
		ret[i] = ft_strdup(src[i]);
		i++;
	}
	return (ret);
}
