/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncorrear <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 18:08:25 by ncorrear          #+#    #+#             */
/*   Updated: 2025/12/05 18:11:59 by ncorrear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <unistd.h>

int	is_input_valid(size_t nb_args, char **args)
{
	size_t	i;

	if (nb_args > 6 || nb_args < 5)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	i = 1;
	while (i < nb_args)
	{
		if (ft_atoi(args[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}
