/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdelilah <abdelilah@student.42.fr>        +#+  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 10:00:00 by abdelilah          #+#    #+#          */
/*   Updated: 2025/02/23 10:00:00 by abdelilah         ###   ########.fr    */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_elements(char *str)
{
	int	count;
	int	in_number;
	int	i;

	count = 0;
	in_number = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != ' ' && !in_number)
		{
			count++;
			in_number = 1;
		}
		else if (str[i] == ' ')
			in_number = 0;
		i++;
	}
	return (count);
}

int	get_total_count(int argc, char **argv)
{
	int	count;

	count = 0;
	while (--argc > 0)
		count += count_elements(argv[argc]);
	return (count);
}

static char	**alloc_and_check(int count)
{
	char	**args;

	args = malloc(sizeof(char *) * (count + 1));
	if (!args)
		err("Error");
	return (args);
}

static void	fill_args(char **args, char **temp, int *args_index)
{
	int	j;

	j = 0;
	while (temp[j])
	{
		args[*args_index] = ft_strdup(temp[j]);
		if (!args[*args_index])
			(free_mem(temp), free_mem(args), err("Error"));
		(*args_index)++;
		j++;
	}
}

char	**parse_data(char **argv, int count)
{
	int		i;
	int		args_index;
	char	**args;
	char	**temp;

	args_index = 0;
	args = alloc_and_check(count);
	i = 1;
	while (argv[i])
	{
		temp = ft_split(argv[i]);
		if (!temp)
			(free_mem(args), err("Error"));
		fill_args(args, temp, &args_index);
		free_mem(temp);
		i++;
	}
	args[args_index] = NULL;
	return (args);
}
