/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarrayadd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glouyot <glouyot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 19:45:52 by glouyot           #+#    #+#             */
/*   Updated: 2017/10/09 19:56:49 by glouyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strarrayadd(char **src, char *add)
{
	char	**ret;
	int		i;
	size_t	s;

	s = ft_str_tab_len(src);
	if (!(ret = (char **)ft_memalloc(sizeof(char *) * (s + 1))))
		return (src);
		i = 0;
	while (src[i])
	{
		ret[i] = ft_strdup(src[i]);
		i++;
	}
	ret[i] = ft_strdup(add);
	free(add);
	ret[i + 1] = NULL;
	return (ret);
}