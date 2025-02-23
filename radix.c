/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdelilah <abdelilah@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 15:30:33 by abdelilah         #+#    #+#             */
/*   Updated: 2025/02/23 15:30:39 by abdelilah        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bits(t_list **stack)
{
	t_list	*head;
	int		max;
	int		max_bits;

	head = *stack;
	max = head->index;
	max_bits = 0;
	while (head)
	{
		if (head->index > max)
			max = head->index;
		head = head->next;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

static void	process_stack(t_list **stack_a, t_list **stack_b, int size, int i)
{
	t_list	*head_a;
	int		j;

	j = 0;
	while (j++ < size)
	{
		head_a = *stack_a;
		if (((head_a->index >> i) & 1) == 1)
			ra(stack_a);
		else
			pb(stack_a, stack_b);
	}
}

static void	restore_stack(t_list **stack_a, t_list **stack_b)
{
	while (ft_lstsize(*stack_b) != 0)
		pa(stack_a, stack_b);
}

void	radix_sort(t_list **stack_a, t_list **stack_b)
{
	int	size;
	int	max_bits;
	int	i;

	if (!stack_a || !*stack_a)
		return ;
	size = ft_lstsize(*stack_a);
	max_bits = get_max_bits(stack_a);
	i = 0;
	while (i < max_bits)
	{
		process_stack(stack_a, stack_b, size, i);
		restore_stack(stack_a, stack_b);
		i++;
	}
}
