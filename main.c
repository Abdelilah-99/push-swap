/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdelilah <abdelilah@student.42.fr>        +#+  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 16:39:06 by abdelilah          #+#    #+#          */
/*   Updated: 2025/02/22 22:30:35 by abdelilah         ###   ########.fr    */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	**create_and_init_stack(void)
{
	t_list	**stack;

	stack = (t_list **)malloc(sizeof(t_list *));
	if (!stack)
		return (NULL);
	*stack = NULL;
	return (stack);
}

static void	fill_stack(t_list **stack, char **numbers)
{
	t_list	*new_node;
	int		i;

	i = 0;
	while (numbers[i])
	{
		new_node = ft_lstnew(ft_atoi(numbers[i]));
		if (!new_node)
		{
			free_stack(stack);
			err("Error");
		}
		ft_lstadd_back(stack, new_node);
		i++;
	}
	index_stack(stack);
}

static void	sort_stack(t_list **stack_a, t_list **stack_b)
{
	int	size;

	size = ft_lstsize(*stack_a);
	if (size <= 5)
		simple_sort(stack_a, stack_b);
	else
		radix_sort(stack_a, stack_b);
}

static void	free_all(t_list **stack_a, t_list **stack_b, char **args)
{
	free_stack(stack_a);
	free_stack(stack_b);
	free_mem(args);
}

int	main(int argc, char **argv)
{
	t_list	**stack_a;
	t_list	**stack_b;
	char	**parsed_args;
	int		count;

	count = get_total_count(argc, argv);
	parsed_args = parse_data(argv, count);
	check_input(parsed_args);
	if (count == 0)
		err("Error");
	stack_a = create_and_init_stack();
	stack_b = create_and_init_stack();
	if (!stack_a || !stack_b)
	{
		free_mem(parsed_args);
		if (stack_a)
			free_stack(stack_a);
		err("Error");
	}
	fill_stack(stack_a, parsed_args);
	if (!is_sorted(stack_a))
		sort_stack(stack_a, stack_b);
	free_all(stack_a, stack_b, parsed_args);
	return (0);
}
