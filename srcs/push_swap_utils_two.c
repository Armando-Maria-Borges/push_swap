/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_two.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborges <aborges@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 04:40:23 by aborges           #+#    #+#             */
/*   Updated: 2024/08/02 18:18:53 by aborges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	skip_whitespace(char **str)
{
	while (**str == 9 || **str == 32 || **str == '\n')
		(*str)++;
}

void	copy_word(char *dest, char **src)
{
	int	k;

	k = 0;
	while (**src && **src != 9 && **src != 32 && **src != '\n')
	{
		dest[k] = **src;
		k++;
		(*src)++;
	}
	dest[k] = '\0';
}

char	**ft_simple_split(char *str)
{
	static char	mat[250][250];
	static char	*result[250];
	int			j;

	j = 0;
	skip_whitespace(&str);
	while (*str)
	{
		copy_word(mat[j], &str);
		result[j] = mat[j];
		j++;
		skip_whitespace(&str);
	}
	result[j] = NULL;
	return (result);
}

int	ft_atoi_stack(const char *str, t_list **stack_a)
{
	int	i;
	int	neg;
	int	res;

	i = 0;
	neg = 1;
	res = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (str[i] - '0') + (res * 10);
		i++;
	}
	(void)stack_a;
	if (str[i] != '\0')
		ft_display_error(stack_a);
	return (res * neg);
}
