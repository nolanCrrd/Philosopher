/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncorrear <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 11:34:19 by ncorrear          #+#    #+#             */
/*   Updated: 2025/12/07 15:23:34 by ncorrear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"
#include "libft.h"
#include "ft_printf.h"
#include <bits/pthreadtypes.h>
#include <pthread.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

static int	create_info(int launch, t_thread_info **infos,
	pthread_t *threads_ids)
{
	infos[launch] = ft_calloc(1, sizeof(t_thread_info));
	if (infos[launch] == NULL)
	{
		free(threads_ids);
		free_2d((void **)infos, free);
		ft_dprintf(2, "Malloc error\n");
		return (1);
	}
	return (0);
}

static int	launch_philos(pthread_t *threads_ids, t_thread_info **infos,
	t_philo **philos, t_global_data	*data)
{
	int		launch;
	t_philo	*current;

	launch = 0;
	while (launch < data->number_of_philosopher)
	{
		if (create_info(launch, infos, threads_ids))
			return (1);
		current = philos[launch];
		infos[launch]->philo = current;
		infos[launch]->data = data;
		infos[launch]->left = data->forks[
			FT_MOD(launch - ((launch % 2 == 0) * -2 + 1),
				data->number_of_philosopher)];
		infos[launch]->right = data->forks[
			FT_MOD(launch + ((launch % 2 == 0) * -2 + 1),
				data->number_of_philosopher)];
		pthread_create(&threads_ids[launch], NULL,
			philosopher_routine, infos[launch]);
		launch++;
		usleep(1000);
	}
	return (0);
}

void	philosopher(t_global_data *data, t_philo **philos)
{
	pthread_t		*threads_ids;
	t_thread_info	**infos;
	t_thread_moni	*info_moni;
	int				launch;

	if (init_threads_creation(&threads_ids, &infos, &info_moni, data))
		return ;
	info_moni->philos = philos;
	info_moni->data = data;
	pthread_create(&threads_ids[data->number_of_philosopher],
		NULL, monitoring_routine, info_moni);
	if (launch_philos(threads_ids, infos, philos, data) == 0)
	{
		launch = 0;
		pthread_join(threads_ids[data->number_of_philosopher], NULL);
		while (launch < data->number_of_philosopher)
			pthread_detach(threads_ids[launch++]);
	}
	free(threads_ids);
	free(info_moni);
	free_2d((void **)infos, free);
}

int	main(int argc, char **argv)
{
	t_global_data	*data;
	t_philo			**philos;

	if (!is_input_valid(argc, argv))
		return (2);
	data = get_global_data(argc, argv);
	if (data == NULL)
		return (1);
	philos = get_philo_list(data->number_of_philosopher);
	data->forks = get_fork_list(data->number_of_philosopher);
	set_actual_time(&data->start_time, 0);
	philosopher(data, philos);
	clear_forks(data->forks);
	free(data);
	free_2d((void **)philos, free);
	return (0);
}
