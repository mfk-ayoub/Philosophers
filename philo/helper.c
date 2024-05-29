/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 06:23:09 by ayel-mou          #+#    #+#             */
/*   Updated: 2024/05/29 06:42:46 by ayel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	current_time(void)
{
	struct timeval	tv;
	long long		milliseconds;

	gettimeofday(&tv, NULL);
	milliseconds = (long long)tv.tv_sec * 1000 + (long long)tv.tv_usec / 1000;
	return (milliseconds);
}

void	eating(t_philosopher *philosopher)
{
	long long	time;

	time = current_time();
	printf("%lld Philosopher %d is eating\n", time, philosopher->id);
}

// void	sleeping(t_philosopher *philosopher)
// {
// }

// void	thinking(t_philosopher *philosopher)
// {
// }
