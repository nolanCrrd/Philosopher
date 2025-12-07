/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncorrear <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 17:30:50 by ncorrear          #+#    #+#             */
/*   Updated: 2025/12/07 15:28:32 by ncorrear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"
#include <pthread.h>
#include <stddef.h>
#include <stdlib.h>

void	clear_philos(t_philo **philos)
{
	size_t	i;

	i = 0;
	while (philos[i])
	{
		free(philos[i]);
		i++;
	}
	free(philos);
}

void	clear_forks(t_fork **forks)
{
	size_t	i;

	i = 0;
	while (forks[i])
	{
		pthread_mutex_destroy(&forks[i]->mutex);
		free(forks[i]);
		i++;
	}
	free(forks);
}
