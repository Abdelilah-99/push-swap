/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdelilah <abdelilah@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 16:39:04 by abdelilah         #+#    #+#             */
/*   Updated: 2025/02/21 16:39:05 by abdelilah        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


static t_list	*find_min(t_list *stack)
{
	t_list	*min;
	t_list	*curr;

	min = NULL;
	curr = stack;
	while (curr)
	{
		if (curr->index == -1 && (!min || curr->value < min->value))
			min = curr;
		curr = curr->next;
	}
	return (min);
}

void	index_stack(t_list **stack)
{
	t_list	*curr;
	int		i;

	i = 0;
	curr = find_min(*stack);
	while (curr)
	{
		curr->index = i++;
		curr = find_min(*stack);
	}
}
