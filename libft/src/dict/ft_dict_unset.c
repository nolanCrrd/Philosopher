/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncorrear <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 09:24:24 by ncorrear          #+#    #+#             */
/*   Updated: 2025/12/07 09:26:38 by ncorrear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dict_unset(t_dict *dict, char *key)
{
	t_dict_node	*node;
	t_dict_node *prec_node;

	node = dict->entry;
	while (node)
	{
		if (ft_strcmp(key, node->key) == 0)
		{
			if (prec_node != NULL)
				prec_node->next = node->next;
			ft_dict_clear_node(node, NULL);
		}
		prec_node = node;
		node = node->next;
	}
}
