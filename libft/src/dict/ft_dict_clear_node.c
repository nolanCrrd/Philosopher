/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict_clear_node.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncorrear <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 09:18:41 by ncorrear          #+#    #+#             */
/*   Updated: 2025/12/07 09:21:35 by ncorrear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_dict_clear_node(t_dict_node *node, void (*del)(void *))
{
	free(node->key);
	if (del != NULL)
		del(node->content);
	free(node);
}
