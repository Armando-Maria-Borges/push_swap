/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborges <aborges@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 16:13:31 by aborges           #+#    #+#             */
/*   Updated: 2024/08/06 16:34:04 by aborges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_init_stack(t_list **stack_a, int argc, char **argv)
{
	t_list	*tmp;
	int		i;

	i = argc - 1;
	while (i >= 0)
	{
		tmp = (t_list *)malloc(sizeof(t_list));
		if (!tmp)
			return ;
		tmp->value = ft_atoi_stack(argv[i], stack_a);
		tmp->next = *stack_a;
		*stack_a = tmp;
		i--;
	}
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	ft_check_only_number(argv);
	ft_equal_value(argv, 1);
	ft_check_arg(argc, argv, &stack_a, &stack_b);
	ft_free_stack(&stack_a);
	ft_free_stack(&stack_b);
	return (0);
}
