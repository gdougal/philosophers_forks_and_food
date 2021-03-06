/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdougal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 14:15:32 by gdougal           #+#    #+#             */
/*   Updated: 2021/01/16 14:15:33 by gdougal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	init_philo(t_philo *phd)
{
	pthread_mutex_lock(&phd->info->last_eat);
	phd->t_start = time_start();
	pthread_mutex_unlock(&phd->info->last_eat);
	phd->last_eat = phd->t_start;
}
