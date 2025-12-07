/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict_get.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncorrear <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 09:00:24 by ncorrear          #+#    #+#             */
/*   Updated: 2025/12/07 09:03:50 by ncorrear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_dict_get(t_dict *dict, char *key)
{
	t_dict_node	*node;

	node = dict->entry;
	while (node)
	{
		if (ft_strcmp(node->key, key) == 0)
			return (node->content);
		node = node->next;
	}
	return (NULL);
}
