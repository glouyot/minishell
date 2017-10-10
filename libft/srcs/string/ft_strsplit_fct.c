/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_fct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glouyot <glouyot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 14:43:39 by glouyot           #+#    #+#             */
/*   Updated: 2017/10/09 13:28:03 by glouyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	ft_size_word(char const *s, int (*split)(int))
{
	size_t		count;

	count = 0;
	while (s[count] != '\0' && (*split)(s[count]) == 0)
		count++;
	return (count);
}

static char		*ft_next_word(char const *s, int (*split)(int))
{
	while (*s && (*split)(*s) == 1)
		s++;
	return ((char *)s);
}

static void		ft_clean(char **s, size_t n)
{
	while (n--)
		ft_strdel(&s[n]);
	ft_strdel(s);
}

static size_t	ft_counts(char *s, int (*split)(int))
{
	size_t		count;
	int			i;

	i = 0;
	count = 0;
	while (s[i] != '\0' && (*split)(s[i]) == 1)
		i++;
	while (s[i] != '\0')
	{
		while (s[i] != '\0' && (*split)(s[i]) == 0)
			i++;
		count++;
		while (s[i] != '\0' && (*split)(s[i]) == 1)
			i++;
	}
	return (count);
}

char			**ft_strsplit_fct(char const *s, int (*split)(int))
{
	char		**ret;
	size_t		word;
	size_t		i;

	if (!s)
		return (NULL);
	word = ft_counts((char *)s, split);
	if (!(ret = (char **)malloc(sizeof(char *) * (word + 1))))
		return (NULL);
	i = 0;
	while (i < word)
	{
		s = ft_next_word(s, split);
		ret[i] = ft_strsub(s, 0, ft_size_word(s, split));
		if (ret[i] == NULL)
		{
			ft_clean(ret, i);
			return (NULL);
		}
		i++;
		s += ft_size_word(s, split);
	}
	ret[word] = NULL;
	return (ret);
}
