/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philosopher.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncorrear <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 14:47:21 by ncorrear          #+#    #+#             */
/*   Updated: 2025/12/07 15:28:20 by ncorrear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "philosopher.h"
#include <pthread.h>
#include <stdlib.h>

int	init_threads_creation(pthread_t **threads_ids, t_thread_info ***infos,
	t_thread_moni	**info_moni, t_global_data *data)
{
	*threads_ids = ft_calloc(data->number_of_philosopher + 1,
			sizeof(pthread_t));
	*infos = ft_calloc(data->number_of_philosopher + 1,
			sizeof(t_thread_info *));
	*info_moni = ft_calloc(1, sizeof(t_thread_moni));
	if (*infos == NULL || *threads_ids == NULL || *info_moni == NULL)
	{
		free(*info_moni);
		free(*infos);
		free(*threads_ids);
		ft_dprintf(2, "Malloc Error\n");
		return (1);
	}
	return (0);
}
