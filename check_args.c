/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdelilah <abdelilah@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 16:38:58 by abdelilah         #+#    #+#             */
/*   Updated: 2025/02/22 22:08:37 by abdelilah        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int is_valid_number(char *str)
{
    int i;

    i = 0;
    if (str[0] == '-' || str[0] == '+')
    {
        i++;
        if (!str[i])
            return (0);
    }
    while (str[i])
    {
        if (!ft_isdigit(str[i]))
            return (0);
        i++;
    }
    return (1);
}

static int check_err_dup(long num, char **args, int current_pos)
{
    while (args[++current_pos])
    {
        if (ft_atoi(args[current_pos]) == num)
            return (1);
    }
    return (0);
}

static int is_within_int_range(long num)
{
    return (num >= -2147483648 && num <= 2147483647);
}

void	check_input(char **args)
{
    int start;
    long num;

    start = 0;
    while (args[start])
    {
        if (!is_valid_number(args[start]))
        {
            free_mem(args);
            err("Error");
        }
        num = ft_atoi(args[start]);
        if (!is_within_int_range(num) || check_err_dup(num, args, start))
        {
            free_mem(args);
            err("Error");
        }
        start++;
    }
}
