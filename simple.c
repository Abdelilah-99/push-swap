/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdelilah <abdelilah@student.42.fr>        +#+  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 16:39:24 by abdelilah          #+#    #+#          */
/*   Updated: 2025/02/23 02:45:18 by abdelilah         ###   ########.fr    */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_min(t_list **stack)
{
	t_list	*current;
	int		min;

	current = *stack;
	min = current->index;
	while (current)
	{
		if (current->index < min)
			min = current->index;
		current = current->next;
	}
	return (min);
}

static void	handle_sort_3_cases(t_list **stack, int f, int s, int t)
{
	if (f > s && s < t && f < t)
		sa(stack);
	else if (f > s && s > t)
	{
		sa(stack);
		rra(stack);
	}
	else if (f > s && s < t && f > t)
		ra(stack);
	else if (f < s && s > t && f < t)
	{
		sa(stack);
		ra(stack);
	}
	else if (f < s && s > t && f > t)
		rra(stack);
}

static void	sort_3(t_list **stack)
{
	int	first;
	int	second;
	int	third;

	first = (*stack)->index;
	second = (*stack)->next->index;
	third = (*stack)->next->next->index;
	handle_sort_3_cases(stack, first, second, third);
}

static void	sort_4_or_5(t_list **stack_a, t_list **stack_b, int size)
{
	int	min;
	int	i;

	i = size - 3;
	while (i > 0)
	{
		min = get_min(stack_a);
		while ((*stack_a)->index != min)
		{
			if ((*stack_a)->next->index == min)
				ra(stack_a);
			else
				rra(stack_a);
		}
		pb(stack_a, stack_b);
		i--;
	}
	sort_3(stack_a);
	while (i < size - 3)
	{
		pa(stack_a, stack_b);
		i++;
	}
}

void	simple_sort(t_list **stack_a, t_list **stack_b)
{
	int	size;

	size = ft_lstsize(*stack_a);
	if (size <= 1 || is_sorted(stack_a))
		return ;
	if (size == 2)
		sa(stack_a);
	else if (size == 3)
		sort_3(stack_a);
	else if (size == 4 || size == 5)
		sort_4_or_5(stack_a, stack_b, size);
}
