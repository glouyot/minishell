/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glouyot <glouyot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 13:15:03 by glouyot           #+#    #+#             */
/*   Updated: 2017/05/30 15:08:42 by glouyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LST_H
# define FT_LST_H

typedef	struct			s_list
{
	void				*content;
	size_t				content_size;
	struct s_list		*next;
}						t_list;

void					ft_lstadd(t_list **alst, t_list *new);
t_list					*ft_lstat(t_list *lst, size_t n);
size_t					ft_lstcount(t_list *lst);
void					ft_lstdel(t_list **alst, void (*del) (void *, size_t));
void					ft_lstdelone(t_list **alst,
		void (*del)(void *, size_t));
void					ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list					*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list					*ft_lstnew(void const *content, size_t content_size);
void					ft_lst_sort(t_list *lst, int (*f)(t_list *lst1,
								t_list *lst2, int rev), int r);
void					ft_lst_sort_inv(t_list *lst, int (*f)(t_list *lst1,
								t_list *lst2));

#endif
