/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 19:34:07 by ayel-mou          #+#    #+#             */
/*   Updated: 2024/07/23 13:57:39 by ayel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_parameter(t_input *input, int ac, char **av)
{
	input->how_many = ft_atoi(av[1]);
	input->time_to_die = ft_atoi(av[2]);
	input->time_to_eating = ft_atoi(av[3]);
	input->time_to_sleeping = ft_atoi(av[4]);
	if (ac == 6)
		input->how_many_eat = ft_atoi(av[5]);
	else
		input->how_many_eat = 0;
}

void *routine(void *argv)
{
	t_philo *philo;
	
	philo = (t_philo *)argv;
	// while (1)
    // {
		// printf("philo = %d | right fokr = %d | left fork = %d\n", philo->id, philo->r_forks->id, philo->l_forks->id);
		
		pthread_mutex_lock(&philo->l_forks->lock);
		printf("has taken a left fork %d\n", philo->id);
		pthread_mutex_lock(&philo->r_forks->lock);
		printf("has taken a right fork %d\n", philo->id);
		pthread_mutex_unlock(&philo->l_forks->lock);
		pthread_mutex_unlock(&philo->r_forks->lock);
	// 
    return NULL;
}

void destory_all(t_philo *philo)
{
	int i;

	i = -1;
	while (++i < philo->input->how_many)
	{
		pthread_mutex_destroy(&philo->input->forks[i].lock);
	}
	
	free(philo);
}


int	main(int ac, char **av)
{
	t_input	input;
	t_philo *philo;
	
	if (ac == 5 || ac == 6)
	{
		check_agrc(av);
		init_parameter(&input, ac, av);
		philo = (t_philo *)malloc(sizeof(t_philo) * input.how_many);
		if (!philo)
			return(1);
		if (!!init_philo(philo,&input))
			return(destory_all(philo),1);
		
		destory_all(philo);
	}
	else
    	desplay_error(&input, ac, av);
}
