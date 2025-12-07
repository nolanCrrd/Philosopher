/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncorrear <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 09:22:40 by ncorrear          #+#    #+#             */
/*   Updated: 2025/12/07 09:24:12 by ncorrear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_dict_clear(t_dict *dict, void (*del)(void *))
{
	t_dict_node	*node;
	t_dict_node	*next_node;

	node = dict->entry;
	while (node)
	{
		next_node = node->next;
		ft_dict_clear_node(node, del);
		node = next_node;
	}
	free(dict);
}
