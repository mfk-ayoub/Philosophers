/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 18:36:33 by ayel-mou          #+#    #+#             */
/*   Updated: 2024/07/25 17:18:46 by ayel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	time_ms(void)
{
	struct timeval	tv;
	long long		milliseconds;

	gettimeofday(&tv, NULL);
	milliseconds = (long long)tv.tv_sec * 1000 + (long long)tv.tv_usec / 1000;
	return (milliseconds);
}

// void	print_status(t_philo *philo, const char *status)
// {
// 	pthread_mutex_lock(&philo->p_status);
// 	printf("%ld %d  %s", philo->id, status);
// 	pthread_mutex_unlock(&philo->p_status);
// }
