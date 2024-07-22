/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 14:10:42 by ayel-mou          #+#    #+#             */
/*   Updated: 2024/07/22 17:35:24 by ayel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void init_forks(t_philo *philo,t_input *input)
{
	int i;
	(void)philo;
	input->forks = malloc(sizeof(pthread_mutex_t) * input->how_many);
	if (!input->forks)
		return ;
	i = -1;
	while (++i < input->how_many)
	{
		if (!!pthread_mutex_init(&input->forks[i],NULL))
		{
			free(input->forks);
			return ;
			
		}

	}
}

int	init_philo(t_philo *philo ,t_input *input)
{
	int	i;

	i = -1;
	init_forks(philo,input);
	while (++i < input->how_many)
	{
		philo[i].id = i + 1;
		philo[i].input = input;
		philo[i].l_forks = input->forks[i];
		philo[i].r_forks = philo[i + 1 % input->how_many].l_forks;		

		if (!!pthread_create(&philo[i].philo_n, NULL, &routine, (void *)philo))
			return(0);
		
	}
	i = -1;
	while (++i < input->how_many)
	{
		if (!!pthread_join(philo[i].philo_n,NULL))
			return (0);
	}
	
	return (1);
}
