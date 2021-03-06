/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdougal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 15:19:25 by gdougal           #+#    #+#             */
/*   Updated: 2021/01/15 15:19:27 by gdougal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

static void	pre_init(t_philo **phd, t_info *info)
{
	int	i;

	i = 0;
	while (i < info->rules[SUM_PH])
	{
		(*phd)[i].info = info;
		(*phd)[i].name = i + 1;
		(*phd)[i].t_start = 0;
		(*phd)[i].curent_time = 0;
		(*phd)[i].last_eat = 0;
		(*phd)[i].last_eat = 0;
		(*phd)[i].th = 0;
		(*phd)[i].must_eat = (*phd)[i].info->rules[T_MST_E];
		i++;
	}
}

int			main(int argc, char **argv)
{
	t_philo			*philo;
	t_info			info;
	int				status;

	status = 0;
	status = philo_pars(argv, argc, &info);
	if (!status)
		if (!(philo = malloc((info.rules[SUM_PH]) * sizeof(t_philo))))
			status = 3;
	if (!status)
	{
		pre_init(&philo, &info);
		if (thread_start(&philo, &info))
			status = 4;
	}
	clear_space(status, &info, &philo);
	return (status);
}
