/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 15:19:58 by sunmin            #+#    #+#             */
/*   Updated: 2020/10/10 00:12:20 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list		*new;
	t_list		*temp;
	t_list		*result;

	if (lst == NULL || f == NULL)
		return (NULL);
	new = NULL;
	while (lst)
	{
		temp = ft_lstnew(f(new));
		if (ft_lstnew(f(new)) == NULL)
		{
			ft_lstclear(&result, del);
		}
		ft_lstadd_back(&result, temp);
		lst = lst->next;
	}
	return (lst);
}
