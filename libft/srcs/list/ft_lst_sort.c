/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glouyot <glouyot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 17:35:51 by glouyot           #+#    #+#             */
/*   Updated: 2017/05/30 15:14:37 by glouyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_sort(t_list *lst, int (*f)(t_list *l1, t_list *l2, int rev),
					int r)
{
	t_list	*lst1;
	t_list	*lst2;

	lst1 = lst;
	lst2 = lst1;
	while (lst1->next)
	{
		while (lst2->next)
		{
			if ((*f)(lst1, lst2, r) < 0)
			{
				ft_memswap(&(lst1)->content, &(lst2->content));
				ft_memswap((void **)(&(lst1->content_size)),
		(void **)(&(lst2->content_size)));
			}
			lst2 = lst2->next;
		}
		lst2 = lst;
		lst1 = lst1->next;
	}
}
