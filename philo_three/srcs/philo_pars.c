/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_pars.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdougal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 14:14:00 by gdougal           #+#    #+#             */
/*   Updated: 2021/01/25 17:16:27 by gdougal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void			semaphore_unlink(void)
{
	sem_unlink("/forks");
	sem_unlink("/waiter");
	sem_unlink("/write");
	sem_unlink("/must_eat");
	sem_unlink("/last_eat");
	sem_unlink("/death");
	sem_unlink("/start");
	sem_unlink("/first");
}

static int	semaphore_init(t_info *info)
{
	info->amdead = 0;
	semaphore_unlink();
	info->forks = sem_open("/forks", O_CREAT, S_IRWXU, info->rules[SUM_PH]);
	info->waiter = sem_open("/waiter", O_CREAT, S_IRWXU, 1);
	info->write = sem_open("/write", O_CREAT, S_IRWXU, 1);
	info->must_eat = sem_open("/must_eat", O_CREAT, S_IRWXU, 0);
	info->last_eat = sem_open("/last_eat", O_CREAT, S_IRWXU, 1);
	info->detah = sem_open("/death", O_CREAT, S_IRWXU, 0);
	info->start = sem_open("/start", O_CREAT, S_IRWXU, 0);
	info->first = sem_open("/first", O_CREAT, S_IRWXU, 1);
	if (info->forks == (sem_t *)-1 || info->waiter == (sem_t *)-1 ||
		info->write == (sem_t *)-1 || info->must_eat == (sem_t *)-1 ||
		info->last_eat == (sem_t *)-1 || info->start == (sem_t *)-1 ||
		info->first == (sem_t *)-1 || info->detah == (sem_t *)-1)
		return (-1);
	return (0);
}

static int	data_mainer(t_info *info, char *argv, int i)
{
	info->rules[i] = ft_atoi(argv);
	if ((info->rules[i] < 2 && i != T_MST_E) || info->rules[i] < 1)
		return (2);
	return (0);
}

int			philo_pars(char **argv, int argc, t_info *info)
{
	int		i;
	int		status;

	if (argc < 5 || argc > 6)
		return (1);
	info->rules[T_MST_E] = -1;
	i = 0;
	while (argv[++i])
	{
		status = data_mainer(info, argv[i], i - 1);
		if (status)
			return (status);
	}
	if (semaphore_init(info))
	{
		semaphore_close(info);
		status = 2;
		return (status);
	}
	return (0);
}
