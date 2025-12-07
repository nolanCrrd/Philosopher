/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict_new_node.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncorrear <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 09:09:53 by ncorrear          #+#    #+#             */
/*   Updated: 2025/12/07 09:11:56 by ncorrear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_dict_node	*ft_dict_new_node(char *key, void *content)
{
	t_dict_node	*new;
	char		*dupped_key;

	new = ft_calloc(1, sizeof(t_dict_node));
	if (new == NULL)
		return (NULL);
	dupped_key = ft_strdup(key);
	if (dupped_key == NULL)
	{
		free(new);
		return (NULL);
	}
	new->key = dupped_key;
	new->content = content;
	return (new);
}
