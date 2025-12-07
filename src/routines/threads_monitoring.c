/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_monitoring.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncorrear <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 14:35:38 by ncorrear          #+#    #+#             */
/*   Updated: 2025/12/07 15:30:05 by ncorrear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"
#include <stdlib.h>
#include <stdio.h>

void	update_philo(t_philo *current_philo, t_thread_moni *monitoring)
{
	long	time;

	set_actual_time(&time, monitoring->data->start_time);
	if (time - current_philo->last_eat >= monitoring->data->time_to_die)
	{
		monitoring->data->some_one_dead = 1;
		printf("%ldms: %i is died\n", time, current_philo->philo_number);
	}
	if (current_philo->state == EATING)
		printf("%ldms: %i is eating\n", time, current_philo->philo_number);
	else if (current_philo->state == SLEEPING)
		printf("%ldms: %i is sleeping\n", time, current_philo->philo_number);
	else if (current_philo->state == THINKING)
		printf("%ldms: %i is thinking\n", time, current_philo->philo_number);
	else if (current_philo->state == FORK1 || current_philo->state == FORK2)
		printf("%ldms: %i has taken a fork\n", time,
			current_philo->philo_number);
	else if (current_philo->state == FINISH)
	{
		monitoring->data->some_one_dead = 1;
		printf("%ldms: %i has eated \
enought\n", time, current_philo->philo_number);
	}
}

void	*monitoring_routine(void *ptr)
{
	t_thread_moni	*monitoring;
	size_t			i;
	t_philo			*current_philo;
	long			time;

	monitoring = (t_thread_moni *)ptr;
	while (1)
	{
		i = 0;
		while (monitoring->philos[i])
		{
			set_actual_time(&time, monitoring->data->start_time);
			current_philo = monitoring->philos[i];
			update_philo(current_philo, monitoring);
			if (monitoring->data->some_one_dead)
				return (NULL);
			current_philo->state = NOTHING;
			i++;
		}
	}
}
