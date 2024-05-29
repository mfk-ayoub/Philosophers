/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 19:34:07 by ayel-mou          #+#    #+#             */
/*   Updated: 2024/05/29 06:51:41 by ayel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	failed_thread(t_input *input)
{
	printf(RED "Failed");
	free(input->philosophers);
	exit(EXIT_FAILURE);
}
void	*routine(void *argv)
{
	t_philosopher	*philosopher;

	philosopher = (t_philosopher *)argv;
	eating(philosopher);
	return (NULL);
}

void	init_philo(t_input *input)
{
	int	i;

	i = -1;
	while (++i < input->how_many)
	{
		input->philosophers[i].id = i + 1;
		if (pthread_create(&input->philosophers[i].thread, NULL, routine,
				&input->philosophers[i]) != 0)
			failed_thread(input);
	}
	i = -1;
	while (++i < input->how_many)
	{
		if (pthread_join(input->philosophers[i].thread, NULL) != 0)
			failed_thread(input);
	}
	free(input->philosophers);
}

void	init_parameter(t_input *input, int ac, char **av)
{
	input->how_many = ft_atoi(av[1]);
	input->time_to_die = ft_atoi(av[2]);
	input->time_to_eating = ft_atoi(av[3]);
	input->time_to_sleeping = ft_atoi(av[4]);
	if (ac == 6)
		input->how_many_eat = ft_atoi(av[5]);
	else
		input->how_many_eat = -1;
	input->forks = malloc(sizeof(t_philosopher) * input->how_many);
	input->philosophers = malloc(sizeof(t_philosopher) * input->how_many);
	if (input->philosophers == NULL)
		exit(EXIT_FAILURE);
}

int	main(int ac, char **av)
{
	t_input	input;

	if (ac == 5 || ac == 6)
	{
		check_agrc(av);
		init_parameter(&input, ac, av);
		init_philo(&input);
		free(input.philosophers);
		free(input.forks);
	}
	else
		desplay_error(&input, ac, av);
}
