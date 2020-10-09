/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 15:05:46 by sunmin            #+#    #+#             */
/*   Updated: 2020/10/09 16:09:29 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list		*now;
	t_list		*nex;

	now = *lst;
	while(now)
	{
		nex = now->next;
		ft_lstdelone(now, del);
		now = nex;
	}
	*lst = NULL;
}
