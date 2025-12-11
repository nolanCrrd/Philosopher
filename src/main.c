/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncorrear <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 11:58:28 by ncorrear          #+#    #+#             */
/*   Updated: 2025/12/11 11:58:39 by ncorrear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(t_philo *philo)
{
	long long	stime;

	stime = philo->ctl->start_time;
	write_message(ft_time(stime, -1), philo, "is thinking", CYAN);
	first_meal(philo, stime);
	usleep(500);
	pthread_mutex_lock(&philo->ctl->mutex);
	while (philo->ctl->status == 0)
	{
		pthread_mutex_unlock(&philo->ctl->mutex);
		philo_cycle(philo, stime);
		usleep(500);
		pthread_mutex_lock(&philo->ctl->mutex);
	}
	pthread_mutex_unlock(&philo->ctl->mutex);
	ft_usleep(500);
	return (NULL);
}

void	monitor(t_philo *philo, long long stime)
{
	t_philo		*tmp;

	tmp = philo;
	while (1)
	{
		pthread_mutex_lock(&philo->ctl->mutex);
		if (ft_time(-1, tmp->last_meal) > tmp->ctl->time_to_die)
		{
			pthread_mutex_unlock(&philo->ctl->mutex);
			break ;
		}
		if (check_if_full(philo) && philo->ctl->num_eat != -1)
		{
			philo->ctl->status = 1;
			pthread_mutex_unlock(&philo->ctl->mutex);
			return ;
		}
		pthread_mutex_unlock(&philo->ctl->mutex);
		tmp = tmp->next;
	}
	pthread_mutex_lock(&philo->ctl->mutex);
	philo->ctl->status = 1;
	pthread_mutex_unlock(&philo->ctl->mutex);
	printf("%s%lldms\t%s|%s #%d %s|%s %s%s\n", YELLOW, ft_time(-1, -1) - stime,
		RESET, MAGENTA, philo->philo_id + 1, RESET, RED, "died", RESET);
}

void	ft_philo(t_control *ctl, t_philo *philo)
{
	int			i;
	t_philo		*tmp;

	i = 0;
	tmp = philo;
	if (ctl->num_of_philo == 1)
		pthread_create(&philo->thread, NULL, (void *)one, philo);
	else
		multi_threads(philo, ctl->num_of_philo);
	tmp = philo->next;
	monitor(philo, ctl->start_time);
	while (i < ctl->num_of_philo)
	{
		pthread_join(tmp->thread, NULL);
		tmp = tmp->next;
		i++;
	}
	ft_clean(philo, ctl, ctl->num_of_philo);
}

int	main(int ac, char **av)
{
	t_control	*control;
	t_philo		*philo;

	control = parsing(ac, av);
	if (!control)
		return (1);
	if (control->num_eat == 0)
	{
		free(control->forks);
		free(control);
		return (0);
	}
	philosophers_init(&philo, control);
	ft_philo(control, philo);
	return (0);
}
