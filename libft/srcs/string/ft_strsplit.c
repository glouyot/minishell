/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glouyot <glouyot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 11:00:10 by glouyot           #+#    #+#             */
/*   Updated: 2017/10/03 11:19:10 by glouyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	ft_size_word(char const *s, char c)
{
	size_t		count;

	count = 0;
	while (s[count] != '\0' && s[count] != c)
		count++;
	return (count);
}

static char		*ft_next_word(char const *s, char c)
{
	while (*s && *s == c)
		s++;
	return ((char *)s);
}

static void		ft_clean(char **s, size_t n)
{
	while (n--)
		ft_strdel(&s[n]);
	ft_strdel(s);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**ret;
	size_t		word;
	size_t		i;

	word = ft_countwords((char *)s, c);
	if (!(ret = (char **)malloc(sizeof(char *) * (word + 1))))
		return (NULL);
	i = 0;
	while (i < word)
	{
		s = ft_next_word(s, c);
		ret[i] = ft_strsub(s, 0, ft_size_word(s, c));
		if (ret[i] == NULL)
		{
			ft_clean(ret, i);
			return (NULL);
		}
		i++;
		s += ft_size_word(s, c);
	}
	ret[word] = NULL;
	return (ret);
}
