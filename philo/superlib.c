/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   superlib.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 15:00:15 by ayel-mou          #+#    #+#             */
/*   Updated: 2024/07/11 11:26:32 by ayel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(int index)
{
	if ('0' <= index && '9' >= index)
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
		{
			printf(RED "Error must have all arguments positive\n"  RESET); 
			exit(EXIT_FAILURE);
		}
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	return (res);
}

void	desplay_error(t_input *input, int ac, char **av)
{
	(void)av;
	(void)input;
	if (ac != 5 && ac != 6)
	{
		printf(RED "╭──── Syntax Error try : \n");
		printf("╰─>" YELLOW " ./philo" RESET ERROR_MSG);
		printf(RED LINE_L RESET);
		printf("\t\t" GREEN "1 ➫ " RESET "number of philosophers \n");
		printf("\t\t" GREEN "2 ➫ " RESET "time to die \n");
		printf("\t\t" GREEN "3 ➫ " RESET "time to eat \n");
		printf("\t\t" GREEN "4 ➫ " RESET "time to sleep  \n");
		printf("\t\t" GREEN "5 ➫ " RESET NUM_EAT);
		printf(RED LINE_L RESET);
		exit(EXIT_FAILURE);
	}
}

void	check_agrc(char **av)
{
	int	i;
	int	j;
	int	flag;

	i = 1;
	while (av[i])
	{
		j = 0;
		flag = 0;
		while (av[i][j])
		{
			if (ft_isdigit(av[i][j]))
				flag = 1;
			j++;
		}
		i++;
		if (flag == 0)
		{
			printf(RED "Error finding string in argument\n"  RESET);
			exit(1);
		}
	}
}
