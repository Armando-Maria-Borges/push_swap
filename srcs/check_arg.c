/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborges <aborges@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 17:11:05 by aborges           #+#    #+#             */
/*   Updated: 2024/08/05 03:42:38 by aborges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_search_space(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_check_param(t_list **stack_a, char **av)
{
	int		i;

	if (!ft_search_space(av[1], 32))
		exit (0);
	av = ft_simple_split(av[1]);
	ft_equal_value(av, 0);
	i = 0;
	while (av[i])
		i++;
	ft_init_stack(stack_a, i, av);
	return (i);
}

int	ft_check_only_number(char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (!ft_very_digit(av[i]))
		{
			ft_printf("Error");
			exit (0);
		}
		i++;
	}
	return (1);
}

int	ft_equal_value(char **av, int position)
{
	int	i;
	int	j;

	i = position;
	while (av[i])
	{
		j = 1 + i;
		while (av[j])
		{
			if (ft_atoi(av[i]) == ft_atoi(av[j]))
			{
				ft_printf("Error");
				exit(0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
