/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 12:59:01 by sunmin            #+#    #+#             */
/*   Updated: 2020/10/06 13:21:08 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstsize(t_list *lst)
{
	int size;

	if (lst == NULL)
		return (0);
	size = 0;
	while(lst)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}
