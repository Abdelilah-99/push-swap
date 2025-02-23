/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdelilah <abdelilah@student.42.fr>        +#+  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 16:39:30 by abdelilah          #+#    #+#          */
/*   Updated: 2025/02/23 15:36:14 by abdelilah         ###   ########.fr    */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	err(char *msg)
{
	ft_putendl_fd(msg, 2);
	exit(1);
}

void	free_mem(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int	is_sorted(t_list **stack)
{
	t_list	*head;

	head = *stack;
	while (head && head->next)
	{
		if (head->value > head->next->value)
			return (0);
		head = head->next;
	}
	return (1);
}

void	ft_putendl_fd(char *s, int fd)
{
	if (!s)
		return ;
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}

void	print_list(t_list *head)
{
	while (head)
	{
		ft_putnbr_fd(head->value, 1);
		ft_putendl_fd("", 1);
		head = head->next;
	}
}
