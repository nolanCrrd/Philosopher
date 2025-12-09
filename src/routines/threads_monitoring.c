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
#include "colors.h"
#include <stdlib.h>
#include <stdio.h>

static void	print_info(t_philo *current_philo, char *state,
	t_thread_moni *monitoring, char *state_color)
{
	long	time;

	set_actual_time(&time, monitoring->data->start_time);
	printf("%s%ldms\t%s|%s #%i %s|%s %s%s\n", YELLOW, time, RESET,
		MAGENTA, current_philo->philo_number, RESET, state_color, state, RESET);
}

void	update_philo(t_philo *current_philo, t_thread_moni *monitoring)
{
	long	time;

	set_actual_time(&time, monitoring->data->start_time);
	if (time - current_philo->last_eat >= monitoring->data->time_to_die)
	{
		monitoring->data->some_one_dead = 1;
		print_info(current_philo, "is died", monitoring, RED);
	}
	if (current_philo->state == EATING)
		print_info(current_philo, "is eating", monitoring, GREEN);
	else if (current_philo->state == SLEEPING)
		print_info(current_philo, "is sleeping", monitoring, BLUE);
	else if (current_philo->state == THINKING)
		print_info(current_philo, "is thinking", monitoring, CYAN);
	else if (current_philo->state == FORK1 || current_philo->state == FORK2)
		print_info(current_philo, "has taken a fork", monitoring, YELLOW);
	else if (current_philo->state == FINISH)
	{
		monitoring->data->some_one_dead = 1;
		print_info(current_philo, "has finished his meal", monitoring, WHITE);
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
