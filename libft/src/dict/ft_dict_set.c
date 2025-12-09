/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict_set.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncorrear <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 08:59:06 by ncorrear          #+#    #+#             */
/*   Updated: 2025/12/07 09:22:07 by ncorrear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_dict_node	*ft_dict_set(t_dict *dict, char *key, void *content)
{
	t_dict_node	*node;
	t_dict_node	*new;

	new = ft_dict_new_node(key, content);
	if (new == NULL)
		return (NULL);
	if (dict->entry == NULL)
	{
		dict->entry = new;
		return (new);
	}
	node = dict->entry;
	while (node->next && ft_strcmp(key, node->key) == 0)
		node = node->next;
	if (ft_strcmp(key, node->key) == 0)
		node->content = content;
	else
	{
		node->next = new;
		return (new);
	}
	ft_dict_clear_node(new, NULL);
	return (node);
}
