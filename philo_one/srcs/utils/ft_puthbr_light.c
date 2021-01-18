/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_light.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdougal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 13:49:35 by gdougal           #+#    #+#             */
/*   Updated: 2021/01/17 13:49:36 by gdougal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	ft_putnbr_light(ssize_t n)
{
	char	num;
	ssize_t	i;
	ssize_t	j;

	i = n;
	j = 10;
	while (i /= 10)
		j *= 10;
	while (j /= 10)
	{
		num = (int)(n / j) + '0';
		write(1, &num, 1);
		n %= j;
	}
}